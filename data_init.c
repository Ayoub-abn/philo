/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdenou <aabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 18:19:34 by aabdenou          #+#    #+#             */
/*   Updated: 2024/07/23 11:09:15 by aabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

 
void data_init(t_program *data)
{
	int i = 0;
	data->dead_flag = 0;
	data->eat_all_meals = data->philo_nb;
	pthread_mutex_init(&data->mx, NULL);
	pthread_mutex_init(&data->flag, NULL);
	pthread_mutex_init(&data->status, NULL);
	pthread_mutex_init(&data->monitor, NULL);
	pthread_mutex_init(&data->meals, NULL);
	data->forks = malloc(sizeof(pthread_mutex_t) * (data->philo_nb));
	while (i < data->philo_nb)
	{
		pthread_mutex_init(&data->forks[i],NULL);
		i++;
	}
	data->philos = malloc (data->philo_nb * sizeof(t_philo));
	i = 0;
	while (i < data->philo_nb)
	{
		if(data->hav_meals == 1)
		{
			data->philos[i].meals = data->limit_meals;
			// printf("%d\n",data->philos[i].meals);
		}
		data->philos[i].philo_id = i + 1;
		data->philos[i].data = data;
		data->philos[i].last_time_eating = get_current_time();
		if(i % 2)
		{
			data->philos[i].l_fork = &data->forks[i];
			data->philos[i].r_fork = &data->forks[(i + 1) % data->philo_nb];

		}
		else 
		{
			data->philos[i].l_fork = &data->forks[(i + 1) % data->philo_nb];
			data->philos[i].r_fork = &data->forks[i];
		}
		i++;
	}
	data->start_time = get_current_time();
}
