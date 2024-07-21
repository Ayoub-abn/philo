/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdenou <aabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 18:37:23 by aabdenou          #+#    #+#             */
/*   Updated: 2024/07/21 17:03:01 by aabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		ft_putstr_fd("gettimeofday() error\n", 2);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}
int	ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = get_current_time();
	while ((get_current_time() - start) < milliseconds)
		usleep(500);
	return (0);
}

void is_print(int i,t_philo *philo)
{
    pthread_mutex_lock(&philo->data->status);
    if(i == 1)
    {
        
	    printf("%ld\t%d is sleeping\n", get_current_time() - philo->data->start_time, philo->philo_id);
    }
    if(i == 2)
    {
	    printf("%ld\t%d is thinking\n", get_current_time() - philo->data->start_time, philo->philo_id);
        
    }
    if(i == 3)
    {
	    printf("%ld\t%d is eating\n",get_current_time() - philo->data->start_time,  philo->philo_id);
        
    }
    if(i == 4)
    {
	    printf("%ld\t%d is dead\n",get_current_time() - philo->data->start_time,  philo->philo_id);       
        
    }
    if(i == 5)
    {
        printf("%ld\t%d has taken a fork\n",get_current_time() - philo->data->start_time, philo->philo_id);
    }
    
    pthread_mutex_unlock(&philo->data->status);
}

void *philo_routine(void *arg)
{
    t_philo *philo = (t_philo *)arg;
    
    while (1) {
        pthread_mutex_lock(&philo->data->flag);
        if(philo->data->dead_flag == 1)
            return (pthread_mutex_unlock(&philo->data->flag), NULL);
        pthread_mutex_unlock(&philo->data->flag);
        
        if (!is_eating(philo))
            break;
            
        pthread_mutex_lock(&philo->data->flag);
        if(philo->data->dead_flag == 1)
            return (pthread_mutex_unlock(&philo->data->flag), NULL);
        pthread_mutex_unlock(&philo->data->flag);
        
        is_sleeping(philo);
        
        pthread_mutex_lock(&philo->data->flag);
        if(philo->data->dead_flag == 1)
            return (pthread_mutex_unlock(&philo->data->flag), NULL);
        pthread_mutex_unlock(&philo->data->flag);
        is_thinking(philo);

    }
    
    return NULL;
}

void create_thread(t_program *data)
{
    data->start_time = get_current_time();
    int i = 0;
    while (i < data->philo_nb) {
        pthread_create(&data->philos[i].thread, NULL, philo_routine, &data->philos[i]);
        i++;
    }
    // pthread_mutex_lock(&data->pr);
    monitor(data);
    // pthread_mutex_unlock(&data->pr);
    i = 0;
    while (i < data->philo_nb) {
        pthread_join(data->philos[i].thread, NULL);
        i++;
    }
}
