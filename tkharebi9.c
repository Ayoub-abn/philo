

#include "philo.h"

int const count = 1000000;
int var = 0;

void *add(void* walo)
{
    int i = 0;
    while (i < count)
    {
        var++;
        i++;
    }
    return NULL;
}
void *ms(void* walo)
{
    int i = 0;
    while (i < count)
    {
        var--;
        i++;
    }
    return NULL;
}
int main()
{
    pthread_t id[2];

    pthread_create(&id[0],NULL,add,NULL);
    pthread_create(&id[1],NULL,ms,NULL);
    pthread_join(id[0],NULL);
    pthread_join(id[1],NULL);

    printf("hna %d \n",var);


    
    return 0;
}
