/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdenou <aabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 18:22:05 by aabdenou          #+#    #+#             */
/*   Updated: 2024/07/21 17:04:28 by aabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void is_sleeping(t_philo *philo)
{
    // pthread_mutex_lock(&philo->data->status);
    is_print(1,philo);
    // pthread_mutex_unlock(&philo->data->status);
    ft_usleep(philo->data->sleep_time );
}

void is_thinking(t_philo *philo)
{
    is_print(2,philo);
}
bool is_eating (t_philo *philo)
{
    if(philo->philo_id % 2 == 0)
    {
        ft_usleep(2);
    }
	pthread_mutex_lock(philo->l_fork);
    pthread_mutex_lock(&philo->data->flag);
    if (philo->data->dead_flag == 1)
        return (pthread_mutex_unlock(&philo->data->flag),pthread_mutex_unlock(philo->l_fork), false);
    pthread_mutex_unlock(&philo->data->flag);
    is_print(5,philo);
	
	pthread_mutex_lock(philo->r_fork);
    pthread_mutex_lock(&philo->data->flag);
    if (philo->data->dead_flag == 1)
        return ( pthread_mutex_unlock(&philo->data->flag),pthread_mutex_unlock(philo->r_fork), pthread_mutex_unlock(philo->l_fork), false);
    pthread_mutex_unlock(&philo->data->flag);
    is_print(5,philo);

    //IS_EATING
    is_print(3,philo);
 
    ft_usleep(philo->data->eat_time);
    pthread_mutex_lock(&philo->data->pr);
	philo->last_time_eating = get_current_time();
    pthread_mutex_unlock(&philo->data->pr);
    
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
    return (true);
}

