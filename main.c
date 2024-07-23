/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdenou <aabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:21:31 by aabdenou          #+#    #+#             */
/*   Updated: 2024/07/22 11:13:44 by aabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"



// ./philo 1 99 77 0000000000000000000000077 22
int	main(int ac, char *av[])
{
	t_program	data;
	
	if (ac != 5 && ac != 6)
		return (ft_putstr_fd("Error\nproblem in argment", 2), 1);
	if (valid_argment(av, &data))
		return (1);
	data_init(&data);
	create_thread(&data);
	
	
}
