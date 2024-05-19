/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdenou <aabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:21:31 by aabdenou          #+#    #+#             */
/*   Updated: 2024/05/19 19:46:05 by aabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_init(t_program *data)
{
	int i = 0;
	while(i < data->philo_nb)
	{
		// pthread_mutex_init(, NULL);
		data->philos[i].id = i + 1;
		data->philos[i].is_dead = 0;
		i++;
	}
	
}

void	data_int(t_program *data)
{
	// data->philo_id = 0;
	data->philos = malloc(data->philo_nb * sizeof(t_philo));
	data->thread = malloc(data->philo_nb * sizeof(pthread_t));
	philo_init(data);
	pthread_mutex_init(&data->mx,NULL);
	// pthread_mutex_init(&program->write_lock,NULL);
	pthread_mutex_init(&data->dead_lock,NULL);
	// pthread_mutex_init(&program->meal_lock,NULL);
}

int	normal(t_program *data)
{
	// pthread_mutex_lock(&data->dead_lock);
	if (data->dead_flag == 1)
		return(/*pthread_mutex_unlock(&data->dead_lock),*/0);
	/*pthread_mutex_unlock(&data->dead_lock);*/
	return(1);
	
}
int id ;
void	*philo_routine(void *walo)
{
	t_program *data = (t_program *)walo;
	pthread_mutex_lock(&data->mx);

	if(data->philos[id].id % 2 == 0)
		printf("yes\n");
	else
		printf("no\n");

	// while ()
	// {
	// 	/* code */
	// }
	
	// printf("hi im philo %d \n", data->philos[id++].id);
	id++;
	pthread_mutex_unlock(&data->mx);
	return (NULL);
}

void	creat_thread(t_program *data)
{
	int i = 0;
	pthread_t *philo = data->thread;
	while (i < data->philo_nb)
	{
		data->philo_id ++;
		pthread_create(&philo[i], NULL, &philo_routine, (void*)data);
		i++;
	}
	i = 0;	
	while (i < data->philo_nb)
	{
		pthread_join(philo[i], NULL);
		i ++;
	}
	free(philo);
}

int	main(int ac, char *av[])
{
	t_program	data;

	// memset(&data,0,sizeof(t_program));
	if (ac != 5 && ac != 6)
		return (ft_putstr_fd("Error\nproblem in argment", 2), 1);
	if (valid_argment(av, &data))
		return (1);
	data_int(&data);
	creat_thread(&data);
}
