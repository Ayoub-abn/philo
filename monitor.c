/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdenou <aabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 18:21:01 by aabdenou          #+#    #+#             */
/*   Updated: 2024/07/24 23:34:30 by aabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	monitor(t_program *data)
{
	int	i;

	while (true)
	{
		if (data->hav_meals)
		{
			lock(&data->meals);
			if (data->eat_all_meals == 0)
			{
				unlock(&data->meals);
				lock(&data->flag);
				data->dead_flag = 1;
				unlock(&data->flag);
				return ;
			}
			unlock(&data->meals);
		}
		i = 0;
		while (i < data->philo_nb)
		{
			lock(&data->monitor);
			if (get_current_time()
				- data->philos[i].last_time_eating > (size_t)data->die_time)
			{
				lock(&data->flag);
				data->dead_flag = 1;
				unlock(&data->flag);
				lock(&data->status);
				printf(RED "%ld %d died\n" RESET, get_current_time()
					- data->start_time, i + 1);
				unlock(&data->status);
				unlock(&data->monitor);
				return ;
			}
			unlock(&data->monitor);
			i++;
		}
	}
}
