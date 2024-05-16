/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdenou <aabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:58:54 by aabdenou          #+#    #+#             */
/*   Updated: 2024/05/16 15:54:00 by aabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		sin;
	int	res;

	i = 0;
	sin = 1;
	res = 0;
	while ((str[i] == ' ' && str[i]) || str[i] == '0')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			sin = -1;
		if (str[i] == '+' || str[i] == '-')
			return (-1);
	}
	if (ft_strlen(&str[i]) >= 12)
		return (-1);
	while ((str[i] >= '0' && str[i] <= '9') && str[i])
		res = res * 10 + (str[i++] - '0');
	if (res * sin > 2147483647 || res * sin <= 0)
		return (-1);
	if (str[i])
		return (-1);
	return (res * sin);
}
int	check_argment(char **av,philo_st *data)
{
	
	data->philo = ft_atoi(av[1]);
	data->die = ft_atoi(av[2]);
	data->eat = ft_atoi(av[3]);
	data->sleep_t = ft_atoi(av[4]);
	if (data->philo == -1 || data->die == -1 || data->eat == -1 || data->sleep_t == -1)
		return (ft_putstr_fd("Error\nThe value of argment is invalid", 2), 1);
	if (data->philo > 200 || data->die < 60 || data->eat < 60 || data->sleep_t < 60)
		return (ft_putstr_fd("Error\nThe value of argment is invalid", 2), 1);
	return (0);
}

int	valid_argment(char **av,philo_st *data)
{
	if (check_argment(av,data))
		return (1);
	crate_thread(data);
	return (0);
}