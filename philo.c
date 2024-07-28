/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdenou <aabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 18:37:23 by aabdenou          #+#    #+#             */
/*   Updated: 2024/07/28 19:36:01 by aabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_flag(t_philo *philo)
{
	lock(&philo->data->flag);
	if (philo->data->dead_flag == 1)
		return (unlock(&philo->data->flag), 1);
	unlock(&philo->data->flag);
	return (0);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->philo_id % 2 == 0)
		usleep(60);
	while (true)
	{
		if (check_flag(philo))
			return (NULL);
		if (!is_eating(philo))
			return (NULL);
		if (check_flag(philo))
			return (NULL);
		is_sleeping(philo);
		if (check_flag(philo))
			return (NULL);
		is_thinking(philo);
		ft_usleep(1, philo);
	}
	return (NULL);
}

void	create_thread(t_program *data)
{
	int	i;

	data->start_time = get_current_time();
	i = 0;
	while (i < data->philo_nb)
	{
		pthread_create(&data->philos[i].thread, NULL, philo_routine,
			&data->philos[i]);
		i++;
	}
	monitor(data);
	i = 0;
	while (i < data->philo_nb)
	{
		pthread_join(data->philos[i++].thread, NULL);
	}
}
