// #include <sys/time.h>
// #include <stdlib.h>
// #include <unistd.h>
// #include <stdio.h>
// long get_time()
// {
//     struct timeval tv;
//     gettimeofday(&tv, NULL);
//     return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
// }

// void mili_sleep(long time)
// {
//     long start = get_time();

//     while(get_time() - start < time);
// }

// int main()
// {
//     // long time = 0;
//     long start = get_time();
//     while (1)
//     {
//         printf("time: %ld\n", get_time() - start);
//         usleep(100000); // to sleep 100 milisec
//         // mili_sleep(100);
//     }
    
// }


#include <sys/time.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

long get_time()
{
    struct timeval tv;

    gettimeofday(&tv,NULL);
    return(tv.tv_sec * 1000 + tv.tv_usec / 1000);
}
void ft_usleep(long time)
{
    long start = get_time();
    while (get_time() - start < time)
    {
        // usleep(500);
    }
    

}

int main()
{
    long start = get_time();
    while (1)
    {
        printf("%ld\n",get_time() - start);
        // usleep(1000000);
        ft_usleep(100);
        // sleep(1);
    }
    
}