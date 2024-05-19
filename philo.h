/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdenou <aabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:14:24 by aabdenou          #+#    #+#             */
/*   Updated: 2024/05/19 19:44:18 by aabdenou         ###   ########.fr       */
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
///////////////////////////och/////////////////////
// typedef struct fr
// {
// 	pthread_mutex_t	mutex;
// 	int				fork_id;
// }					fork_st;


// typedef struct ph
// {
// 	int				id;
// 	long			meals_counter;
// 	bool			full;
// 	long			last_meals_time;
// 	fork_st			*l_fork;
// 	fork_st			*r_fork;
// 	pthread_t		thread_id;
// 	table_st		*table;

// }
// 					philo_st;

///////////////////////////mud///////////////////////////
typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				eating;
	int				meals_eaten;
	size_t			last_meal;
	long			die_time;
	long			eat_time;
	long			sleep_time;
	size_t			start_time;
	long			philo_nb;
	long			limit_meals;
	int				is_dead;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*meal_lock;
}					t_philo;

typedef struct s_program
{
	int				dead_flag;
	long			die_time;
	long			eat_time;
	long			sleep_time;
	int				philo_nb;
	int				philo_id;
	long			limit_meals;

	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	mx;
	t_philo			*philos;
	pthread_t		*thread;
	
	pthread_mutex_t	dead_lock;
	// pthread_mutex_t	meal_lock;
	// pthread_mutex_t	write_lock;
	// t_philo			*philos;
}					t_program;
//////////////////////////////////////////////
// typedef struct s_philo
// {
// 	pthread_t		thread;
// 	long			philo_nb;
// 	long			die_time;
// 	long			eat_time;
// 	long			sleep_time;
// 	long			limit_meals;
// 	long			start;
// 	bool			end;
// 	pthread_mutex_t *r_fork;
// 	pthread_mutex_t *l_fork;
// } table_st;




void				ft_putstr_fd(char *s, int fd);
size_t				ft_strlen(const char *s);
long				ft_atoi(const char *str);
int					check_argment(char **av, t_program *data);
int					valid_argment(char **av, t_program *data);
void				crate_thread(t_program *data);
#endif