

#include "philo.h"
int i;
void *fun(void *x)
{
	
	while (i < 20000000)
	{

		i++;
	}
	
	return NULL;
}

int main()
{
	pthread_t id;
	int j = 0;

	while (j < 8)
	{
		pthread_create(&id,NULL,fun,NULL);
		j++;
	}
	
	pthread_join(id,NULL);
	printf("%d",i);
	return 0;
}

