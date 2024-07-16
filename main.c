/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdenou <aabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:21:31 by aabdenou          #+#    #+#             */
/*   Updated: 2024/07/16 12:23:46 by aabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int	main(int ac, char *av[])
{
	t_program	data;

	// memset(&data,0,sizeof(t_program));
	if (ac != 5 && ac != 6)
		return (ft_putstr_fd("Error\nproblem in argment", 2), 1);
	if (valid_argment(av, &data))
		return (1);
}
