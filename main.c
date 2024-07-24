/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdenou <aabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:21:31 by aabdenou          #+#    #+#             */
/*   Updated: 2024/07/24 17:15:28 by aabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_and_destroy(t_program *data)
{
	pthread_mutex_destroy(&data->flag);
	pthread_mutex_destroy(&data->meals);
	pthread_mutex_destroy(&data->monitor);
	pthread_mutex_destroy(&data->status);
	pthread_mutex_destroy(data->forks);
	pthread_mutex_destroy(data->philos->r_fork);
	pthread_mutex_destroy(data->philos->l_fork);
	free(data->forks);
	free(data->philos);
}

int	main(int ac, char *av[])
{
	t_program	data;

	if (ac != 5 && ac != 6)
		return (ft_putstr_fd("Error\nproblem in argment", 2), 1);
	if (valid_argment(av, &data))
		return (1);
	data_init(&data);
	create_thread(&data);
	free_and_destroy(&data);
}
