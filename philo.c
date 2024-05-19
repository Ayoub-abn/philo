/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdenou <aabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 18:37:23 by aabdenou          #+#    #+#             */
/*   Updated: 2024/05/17 18:59:07 by aabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// void	*crate_philo(void *data)
// {
// 	int static	i;
// 	philo_st	*id;

// 	(void)data;
// 	id = (philo_st *)data;
// 	pthread_mutex_lock(&id->mutex);
// 	++i;
// 	pthread_mutex_unlock(&id->mutex);
// 	printf("hi im philo %d: \n", i);
// 	return (NULL);
// }

// void	crate_thread(table_st *data)
// {
// 	int			i;
// 	pthread_t	id[data->philo - 1];

// 	i = 0;
// 	pthread_mutex_init(&data->mutex, NULL);
// 	while (i < data->philo)
// 	{
// 		pthread_create(&(id[i++]), NULL, crate_philo, data);
// 	}
// 	i = 0;
// 	while (i < data->philo)
// 	{
// 		pthread_join(id[i++], NULL);
// 	}
// }
