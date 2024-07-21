/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdenou <aabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:14:24 by aabdenou          #+#    #+#             */
/*   Updated: 2024/07/21 16:52:40 by aabdenou         ###   ########.fr       */
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

struct s_program ;
// struct s_philo t_philo;

typedef struct s_philo
{
	pthread_t		thread;
	int philo_id;
	long last_time_eating;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	struct s_program *data;
	
}					t_philo;

typedef struct s_program
{
	// pthread_t		*thread;
	int				dead_flag;
	long			die_time;
	long			eat_time;
	long			sleep_time;
	int				philo_nb;
	long			limit_meals;
	long			start_time;
	t_philo			*philos;

	pthread_mutex_t mx;
	pthread_mutex_t status;
	pthread_mutex_t pr;
	pthread_mutex_t flag;
	pthread_mutex_t	*forks;
	// pthread_mutex_t	*l_fork;
	// pthread_mutex_t	dead_lock;
	
}					t_program;




// void	monitor(t_program **data);
size_t	get_current_time(void);
void data_init(t_program *data);
void	monitor(t_program *data);
void is_sleeping(t_philo *philo);
void is_thinking(t_philo *philo);
bool is_eating (t_philo *philo);
void *philo_routine(void *arg);
size_t	get_current_time(void);
int	ft_usleep(size_t milliseconds);
void is_print(int i,t_philo *philo);
void				ft_putstr_fd(char *s, int fd);
size_t				ft_strlen(const char *s);
long				ft_atoi(const char *str);
int					check_argment(char **av, t_program *data);
int					valid_argment(char **av, t_program *data);
// void				crate_thread(t_program *data);
void				data_init(t_program *data);
void create_thread(t_program *data);
#endif