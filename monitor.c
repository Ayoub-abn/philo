/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdenou <aabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 18:21:01 by aabdenou          #+#    #+#             */
/*   Updated: 2024/07/21 16:55:54 by aabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void monitor(t_program *data)
{
    usleep(700);
    while (1)
    {
        for (int i = 0; i < data->philo_nb; i++)
        {
            pthread_mutex_lock(&data->pr);
            if (get_current_time() - data->philos[i].last_time_eating > (size_t)data->die_time)
            {
                pthread_mutex_unlock(&data->pr);
                
                pthread_mutex_lock(&data->flag);
                data->dead_flag = 1;
                pthread_mutex_unlock(&data->flag);
                
                // pthread_mutex_lock(&data->status);
                is_print(4, &data->philos[i]);
                // pthread_mutex_unlock(&data->status);
                return;
            }
            pthread_mutex_unlock(&data->pr);
        }
    }
}