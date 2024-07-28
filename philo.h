/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdenou <aabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:14:24 by aabdenou          #+#    #+#             */
/*   Updated: 2024/07/28 12:56:48 by aabdenou         ###   ########.fr       */
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

// # define RESET "\033[0m"
// # define RED "\033[31m"

# define SLEEPING "is sleeping"
# define THINKING "is thinking"
# define EATING "is eating"
# define TAKEN_A_FORK "has taken a fork"

struct	s_program;

typedef struct s_philo
{
	pthread_t			thread;
	int					philo_id;
	long				last_time_eating;
	pthread_mutex_t		*l_fork;
	pthread_mutex_t		*r_fork;
	int					meals;
	struct s_program	*data;

}						t_philo;

typedef struct s_program
{
	t_philo				*philos;
	////////////////////////////
	long				die_time;
	long				eat_time;
	long				sleep_time;
	long				limit_meals;
	int					philo_nb;
	////////////////////////////
	long				start_time;

	int					dead_flag;
	int					hav_meals;
	int					eat_all_meals;
	pthread_mutex_t		monitor;
	pthread_mutex_t		flag;
	pthread_mutex_t		meals;
	pthread_mutex_t		*forks;

}						t_program;

void					unlock(pthread_mutex_t *mx);
void					lock(pthread_mutex_t *mx);
size_t					get_current_time(void);
bool					data_init(t_program *data);
void					monitor(t_program *data);
void					is_sleeping(t_philo *philo);
void					is_thinking(t_philo *philo);
bool					is_eating(t_philo *philo);
void					*philo_routine(void *arg);
size_t					get_current_time(void);
int						ft_usleep(size_t milliseconds, t_philo *philo);
void					is_print(char *str, t_philo *philo);
void					ft_putstr_fd(char *s, int fd);
size_t					ft_strlen(const char *s);
long					ft_atoi(const char *str);
int						check_argment(char **av, t_program *data);
int						valid_argment(char **av, t_program *data);
void					create_thread(t_program *data);
#endif