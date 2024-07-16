/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdenou <aabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 18:37:23 by aabdenou          #+#    #+#             */
/*   Updated: 2024/07/16 23:38:06 by aabdenou         ###   ########.fr       */
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

void data_init(t_program *data)
{
	int i = 0;
	pthread_mutex_init(&data->mx, NULL);
	data->philos = malloc(data->philo_nb * sizeof(t_philo));
	while (i < data->philo_nb)
	{
		data->philos[i].philo_id = i + 1;
		i++;
	}
	data->thread = malloc(data->philo_nb * sizeof(pthread_t));
	data->start_time = get_current_time();
}
void is_sleeping(t_program *data, int philo_id)
{
	printf("[%ld] the philo %d is sleeping\n", get_current_time() - data->start_time, philo_id);
	usleep(data->sleep_time );
}

void is_thinking(t_program *data, int philo_id)
{
	printf("[%ld] the philo %d is thinking\n", get_current_time() - data->start_time, philo_id);
	usleep(6000);
}
void *philo_routine(void *arg)
{
	t_program *data = (t_program *)arg;
	int philo_id;

	pthread_mutex_lock(&data->mx);
	philo_id = data->philos->philo_id++;
	pthread_mutex_unlock(&data->mx);
	is_sleeping(data, philo_id);
	is_thinking(data, philo_id);

	return (NULL);
}

void create_thread(t_program *data)
{
	int i = 0;
	while (i < data->philo_nb)
		pthread_create(&data->thread[i++], NULL, philo_routine, data);
	i = 0;
	while (i < data->philo_nb)
		pthread_join(data->thread[i++], NULL);
	pthread_mutex_destroy(&data->mx);
	free(data->thread);
	free(data->philos);
}

