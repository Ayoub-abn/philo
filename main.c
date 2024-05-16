/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdenou <aabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:21:31 by aabdenou          #+#    #+#             */
/*   Updated: 2024/05/16 15:56:43 by aabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char *av[])
{
	philo_st data;
	//memset(&data,0,sizeof(data));
	
	if (ac == 5 || ac == 6)
	{
		if (valid_argment(av,&data))
			return (1);
	}
	else
		return (ft_putstr_fd("Error\nproblem in argment", 2),1);
}
