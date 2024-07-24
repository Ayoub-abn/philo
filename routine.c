/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdenou <aabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 18:22:05 by aabdenou          #+#    #+#             */
/*   Updated: 2024/07/24 17:09:23 by aabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	one_philo(t_philo *philo)
{
	while (1)
	{
		lock(&philo->data->flag);
		if (philo->data->dead_flag == 1)
		{
			unlock(philo->l_fork);
			unlock(&philo->data->flag);
			return (1);
		}
		unlock(&philo->data->flag);
	}
	return (0);
}

void	check_meals_nb(t_philo *philo)
{
	lock(&philo->data->meals);
	philo->meals -= 1;
	if (philo->meals == 0)
		philo->data->eat_all_meals--;
	unlock(&philo->data->meals);
}

void	is_sleeping(t_philo *philo)
{
	is_print(SLEEPING, philo);
	ft_usleep(philo->data->sleep_time, philo);
}
void	is_thinking(t_philo *philo)
{
	is_print(THINKING, philo);
}
bool	is_eating(t_philo *philo)
{
	lock(philo->l_fork);
	//------------------------------//
	is_print(TAKEN_A_FORK, philo);
	//------------------------------//
	if (philo->data->philo_nb == 1)
	{
		if (one_philo(philo))
			return (false);
	}
	//----------------------------//
	lock(&philo->data->flag);
	if (philo->data->dead_flag == 1)
		return (unlock(&philo->data->flag), unlock(philo->l_fork), false);
	unlock(&philo->data->flag);
	//----------------------------//
	//----------------------------//
	lock(philo->r_fork);
	//---------------------------//
	lock(&philo->data->flag);
	if (philo->data->dead_flag == 1)
		return (unlock(&philo->data->flag), unlock(philo->r_fork),
			unlock(philo->l_fork), false);
	unlock(&philo->data->flag);
	//------------------------------//
	is_print(TAKEN_A_FORK, philo);
	//------------------------------//
	// IS_EATING
	is_print(EATING, philo);
	//------------------------------//
	if (philo->data->hav_meals)
		check_meals_nb(philo);
	//-----------------------------//
	ft_usleep(philo->data->eat_time, philo);
	//----------last_meal----------//
	lock(&philo->data->monitor);
	philo->last_time_eating = get_current_time();
	unlock(&philo->data->monitor);
	//-----------------------------//
	(unlock(philo->l_fork), unlock(philo->r_fork));
	return (true);
}
