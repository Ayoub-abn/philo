/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdenou <aabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 18:19:34 by aabdenou          #+#    #+#             */
/*   Updated: 2024/07/24 23:38:38 by aabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_mutex(t_program *data)
{
	int	i;

	i = 0;
	pthread_mutex_init(&data->flag, NULL);
	pthread_mutex_init(&data->status, NULL);
	pthread_mutex_init(&data->monitor, NULL);
	pthread_mutex_init(&data->meals, NULL);
	while (i < data->philo_nb)
		pthread_mutex_init(&data->forks[i++], NULL);
}

bool	init_forks_and_philos(t_program *data)
{
	data->forks = malloc(sizeof(pthread_mutex_t) * (data->philo_nb));
	if (!data->forks)
	{
		ft_putstr_fd("memory allocation failed", 2);
		return (false);
	}
	data->philos = malloc(data->philo_nb * sizeof(t_philo));
	if (!data->philos)
	{
		ft_putstr_fd("memory allocation failed\n", 2);
		return (false);
	}
	return (true);
}

bool	data_init(t_program *data)
{
	int	i;

	data->dead_flag = 0;
	data->eat_all_meals = data->philo_nb;
	if (init_forks_and_philos(data) == false)
		return (false);
	init_mutex(data);
	i = -1;
	while (++i < data->philo_nb)
	{
		if (data->hav_meals == 1)
			data->philos[i].meals = data->limit_meals;
		data->philos[i].philo_id = i + 1;
		data->philos[i].data = data;
		data->philos[i].last_time_eating = get_current_time();
		if (i % 2)
		{
			data->philos[i].l_fork = &data->forks[i];
			data->philos[i].r_fork = &data->forks[(i + 1) % data->philo_nb];
		}
		else
		{
			data->philos[i].l_fork = &data->forks[(i + 1) % data->philo_nb];
			data->philos[i].r_fork = &data->forks[i];
		}
	}
	// data->start_time = get_current_time();
	return (true);
}
