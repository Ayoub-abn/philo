/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdenou <aabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:40:28 by aabdenou          #+#    #+#             */
/*   Updated: 2024/07/24 10:36:30 by aabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (s == NULL)
		return ;
	i = ft_strlen(s);
	write(fd, s, i);
}
size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		ft_putstr_fd("gettimeofday() error\n", 2);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}
int	ft_usleep(size_t milliseconds,t_philo *philo)
{
	size_t	start;
	
	start = get_current_time();
	while ((get_current_time() - start) < milliseconds)
	{
		lock(&philo->data->flag);
		if(philo->data->dead_flag == 1)
		{
			unlock(&philo->data->flag);
			return(0);
		}
		unlock(&philo->data->flag);
	}
	return (0);
}
int lock(pthread_mutex_t *mx)
{
    if(pthread_mutex_lock(mx))
        return(ft_putstr_fd("error\npthread_mutex_lock Failed",2),1);
    return(0);
}
int unlock(pthread_mutex_t *mx)
{
    if(pthread_mutex_unlock(mx))
        return(ft_putstr_fd("error\npthread_mutex_unlock Failed",2),1);
    return(0);
}

void is_print(int i,t_philo *philo)
{
	lock(&philo->data->flag);
    if(philo->data->dead_flag == 1)
	{
		unlock(&philo->data->flag);
		return;
	}
    unlock(&philo->data->flag);
	
    lock(&philo->data->status);
    if(i == SLEEPING)
	    printf("%ld %d is sleeping\n", get_current_time() - philo->data->start_time, philo->philo_id);
    if(i == THINKING)
	    printf("%ld %d is thinking\n", get_current_time() - philo->data->start_time, philo->philo_id);
    if(i == EATING)
	    printf(GREEN "%ld %d is eating\n" RESET,get_current_time() - philo->data->start_time,  philo->philo_id);
    // if(i == DIED)
	//     printf(RED  "%ld %d died\n"RESET,get_current_time() - philo->data->start_time,  philo->philo_id);       
    if(i == TAKEN_A_FORK)
        printf("%ld %d has taken a fork\n",get_current_time() - philo->data->start_time, philo->philo_id);
    unlock(&philo->data->status);
    
}
