/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdenou <aabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 18:37:23 by aabdenou          #+#    #+#             */
/*   Updated: 2024/07/23 12:53:21 by aabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"





void *philo_routine(void *arg)
{
    t_philo *philo = (t_philo *)arg;

    // lock(&philo->data->meals);
    //         printf("---->%d\n",philo->data->eat_all_meals);
    
        
    //     if(philo->data->eat_all_meals <= 0)
    //     {
    //         printf("hii\n");
    //         unlock(&philo->data->meals);
    //         return (NULL);
    //     }
        // if(data->philos[i].meals == 0)
    // unlock(&philo->data->meals);
    if(philo->philo_id % 2 == 0)
        ft_usleep(60);
    while (true) 
    {
        lock(&philo->data->flag);
        if(philo->data->dead_flag == 1)
            return (unlock(&philo->data->flag), NULL);
        unlock(&philo->data->flag);

        
        ////////////eating/////////////
        if (!is_eating(philo))
            break;
        ///////////////////////////////

        
        lock(&philo->data->flag);
        if(philo->data->dead_flag == 1)
            return (unlock(&philo->data->flag), NULL);
        unlock(&philo->data->flag);

        
        ///////////sleeping///////////////
        is_sleeping(philo);
        /////////////////////////////////

        
        lock(&philo->data->flag);
        if(philo->data->dead_flag == 1)
            return (unlock(&philo->data->flag), NULL);
        unlock(&philo->data->flag);

        
        //////////thinking//////////////
        is_thinking(philo);
        ////////////////////////////////

    }
    
    return NULL;
}

void create_thread(t_program *data)
{
    data->start_time = get_current_time();
    int i = 0;
    while (i < data->philo_nb)
    {
        pthread_create(&data->philos[i].thread, NULL, philo_routine, &data->philos[i]);
        i++;   
    }

    monitor(data);
    i = 0;
    while (i < data->philo_nb)
        pthread_join(data->philos[i++].thread, NULL);
}
