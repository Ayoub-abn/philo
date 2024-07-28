/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdenou <aabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:21:31 by aabdenou          #+#    #+#             */
/*   Updated: 2024/07/28 14:46:50 by aabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_and_destroy(t_program *data)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&data->flag);
	pthread_mutex_destroy(&data->meals);
	pthread_mutex_destroy(&data->monitor);
	pthread_mutex_destroy(data->forks);
	while (i > data->philo_nb)
	{
		pthread_mutex_destroy(data->philos[i].r_fork);
		pthread_mutex_destroy(data->philos[i].l_fork);
		i++;
	}
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
	if (data_init(&data) == false)
		return (1);
	create_thread(&data);
	free_and_destroy(&data);
}
