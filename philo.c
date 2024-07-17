/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdenou <aabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 18:37:23 by aabdenou          #+#    #+#             */
/*   Updated: 2024/07/17 23:44:11 by aabdenou         ###   ########.fr       */
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
	data->forks = malloc(sizeof(pthread_mutex_t) * data->philo_nb);
	data->philos = malloc(data->philo_nb * sizeof(t_philo));
	while (i < data->philo_nb)
		pthread_mutex_init(&data->forks[i++],NULL);
	i = 0;
	while (i < data->philo_nb)
	{
		data->philos[i].philo_id = i + 1;
		data->philos[i].last_time_eating = get_current_time();
		if(i % 2)
		{
			data->philos->l_fork = &data->forks[i + 1];
			data->philos->r_fork = &data->forks[(i + 1) % data->philo_nb];
		}
		else 
		{
			data->philos->l_fork = &data->forks[(i + 1) % data->philo_nb];
			data->philos->r_fork = &data->forks[i + 1];
			
		}
		i++;
	}
	data->thread = malloc(data->philo_nb * sizeof(pthread_t));
	data->start_time = get_current_time();
}
void is_sleeping(t_program *data, int philo_id)
{
	printf("%ld %d is sleeping\n", get_current_time() - data->start_time, philo_id);
	usleep(data->sleep_time );
}

void is_thinking(t_program *data, int philo_id)
{
	printf("%ld %d is thinking\n", get_current_time() - data->start_time, philo_id);
}
void is_eating (t_program *data,int philo_id)
{
	pthread_mutex_lock(data->philos->l_fork);
	printf("%ld %d has taken a fork\n", get_current_time() - data->start_time, philo_id);
	
	pthread_mutex_lock(data->philos->r_fork);
	printf("%ld %d has taken a fork\n", get_current_time() - data->start_time, philo_id);
	
	printf("%ld %d is eating\n", get_current_time() - data->start_time, philo_id);
	data->philos->last_time_eating = get_current_time() - data->start_time;
	usleep(data->eat_time);
	
	pthread_mutex_unlock(data->philos->r_fork);
	pthread_mutex_unlock(data->philos->l_fork);
}

void *philo_routine(void *arg)
{
	t_program *data = (t_program *)arg;
	int philo_id;

	pthread_mutex_lock(&data->mx);
	philo_id = data->philos->philo_id++;
	pthread_mutex_unlock(&data->mx);
	is_eating(data,philo_id);
	is_sleeping(data, philo_id);
	is_thinking(data, philo_id);
	

	return (NULL);
}

void create_thread(t_program *data)
{
	int i = 0;
	while (i < data->philo_nb)
	{
		pthread_create(&data->thread[i++], NULL, philo_routine, data);	
	}
	i = 0;
	while (i < data->philo_nb)
		pthread_join(data->thread[i++], NULL);
	pthread_mutex_destroy(&data->mx);
	free(data->thread);
	free(data->philos);
}