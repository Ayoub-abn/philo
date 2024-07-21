

#include "philo.h"

// long get_time()
// {
// 	struct timeval tm;

// 	gettimeofday(&tm,NULL);
// 	return ((tm.tv_sec * 1000) + (tm.tv_usec / 1000));
// }

// void ft_sleep(long time)
// {
// 	long stat_time = get_time();
// 	while(get_time() - stat_time < time)
// 		;
// }

// void pick_up_fork(long start_time)
// {
// 	printf("%ld has taken a fork\n", get_time() - start_time);
// 	printf("%ld has taken a fork\n", get_time() - start_time);
// }

// void eating(long start_time)
// {
// 	printf("%ld is eating\n", get_time() - start_time);
// 	ft_sleep(200);
// }

// void sleeping(long start_time)
// {
// 	printf("%ld is sleeping\n", get_time() - start_time);
// 	ft_sleep(200);
// }

// void thinking(long start_time)
// {
// 	printf("%ld is thinking\n", get_time() - start_time);
// }

// int	main(void)
// {

// 	long start_time = get_time();
// 	while(1)
// 	{
// 		pick_up_fork(start_time);
// 		eating(start_time);
// 		sleeping(start_time);
// 		thinking(start_time);
// 	}
// 	return (0);
// }

int				km = 0;
pthread_mutex_t	mx;

void	*km_fun(void *nn)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&mx);
	while (i < 20000000)
	{
		km++;
		i++;
	}
	pthread_mutex_unlock(&mx);
	return (NULL);
}

int	main(int argc, char const *argv[])
{
	pthread_t p1, p2, p3;
	pthread_mutex_init(&mx, NULL);
	printf("km===>start : %d\n", km);
	pthread_create(&p1, NULL, km_fun, NULL);
	pthread_create(&p2, NULL, km_fun, NULL);
	pthread_create(&p3, NULL, km_fun, NULL);
	pthread_join(p1, NULL);
	pthread_join(p2, NULL);
	pthread_join(p3, NULL);
	printf("km===>end : %d", km);
	pthread_mutex_destroy(&mx);
	return (0);
}
