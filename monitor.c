/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdenou <aabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 18:21:01 by aabdenou          #+#    #+#             */
/*   Updated: 2024/07/28 12:57:02 by aabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	hav_meals(t_program *data)
{
	lock(&data->meals);
	if (data->eat_all_meals == 0)
	{
		lock(&data->flag);
		data->dead_flag = 1;
		unlock(&data->flag);
		unlock(&data->meals);
		return (1);
	}
	unlock(&data->meals);
	return (0);
}

void	is_died(t_program *data, int i)
{
	lock(&data->flag);
	data->dead_flag = 1;
	unlock(&data->flag);
	printf("%ld %d died\n", get_current_time() - data->start_time, i
		+ 1);
	unlock(&data->monitor);
}

void	monitor(t_program *data)
{
	int	i;

	while (true)
	{
		if (data->hav_meals)
		{
			if (hav_meals(data))
				return ;
		}
		i = 0;
		while (i < data->philo_nb)
		{
			lock(&data->monitor);
			if (get_current_time()
				- data->philos[i].last_time_eating > (size_t)data->die_time)
			{
				is_died(data, i);
				return ;
			}
			unlock(&data->monitor);
			i++;
		}
	}
}
