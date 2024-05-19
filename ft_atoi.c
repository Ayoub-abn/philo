/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdenou <aabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:58:54 by aabdenou          #+#    #+#             */
/*   Updated: 2024/05/19 19:43:56 by aabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_atoi(const char *str)
{
	int		i;
	int		sin;
	long	res;

	i = 0;
	sin = 1;
	res = 0;
	while ((str[i] == ' ' || str[i] == '\t' || str[i] == '0') && str[i])
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
	if (res * sin > 2147483647 || res * sin < 0)
		return (-1);
	if (str[i])
		return (-1);
	return (res * sin);
}
int	check_argment(char **av, t_program *data)
{
	data->philo_nb = ft_atoi(av[1]);
	data->die_time = (ft_atoi(av[2]) * 1000);
	data->eat_time = (ft_atoi(av[3]) * 1000);
	data->sleep_time = (ft_atoi(av[4]) * 1000);
	if (data->philo_nb <= 0 || data->die_time <= 0 || data->eat_time <= 0
		|| data->sleep_time <= 0)
		return (ft_putstr_fd("Error\nThe value of argment is invalid", 2), 1);
	if (data->philo_nb > 200 || data->die_time < 60000 || data->eat_time < 60000
		|| data->sleep_time < 60000)
		return (ft_putstr_fd("Error\nThe value of argment is invalid", 2), 1);
	if (av[5])
	{
		if ((data->limit_meals = ft_atoi(av[5])) == -1)
			return (ft_putstr_fd("Error\nThe value of argment is invalid", 2),
				1);
	}
	return (0);
}

int	valid_argment(char **av, t_program *data)
{
	if (check_argment(av, data))
		return (1);
	// crate_thread(data);
	return (0);
}