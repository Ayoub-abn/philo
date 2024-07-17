/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdenou <aabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:14:24 by aabdenou          #+#    #+#             */
/*   Updated: 2024/07/17 15:06:44 by aabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>


///////////////////////////mud///////////////////////////
typedef struct s_philo
{
	int philo_id;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	
}					t_philo;

typedef struct s_program
{
	pthread_t		*thread;
	int				dead_flag;
	long			die_time;
	long			eat_time;
	long			sleep_time;
	int				philo_nb;
	long			limit_meals;
	long			start_time;

	pthread_mutex_t	*forks;
	// pthread_mutex_t	*l_fork;
	pthread_mutex_t mx;
	t_philo			*philos;
	// pthread_mutex_t	dead_lock;e
	
}					t_program;





void				ft_putstr_fd(char *s, int fd);
size_t				ft_strlen(const char *s);
long				ft_atoi(const char *str);
int					check_argment(char **av, t_program *data);
int					valid_argment(char **av, t_program *data);
// void				crate_thread(t_program *data);
void				data_init(t_program *data);
void create_thread(t_program *data);
#endif