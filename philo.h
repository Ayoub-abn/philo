
#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
#include <string.h>


typedef struct st
{
	int	philo;
	int	die;
	int	eat;
	int	sleep_t;
	
	pthread_mutex_t    mutex;

}		philo_st;

void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *s);
int		ft_atoi(const char *str);;
int	check_argment(char **av,philo_st *data);
int	valid_argment(char **av,philo_st *data);
void	crate_thread(philo_st *data);
#endif