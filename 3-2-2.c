#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>
int count = 10000;
sem_t *s0 , *s1 , *s2;
void *worker1(void *arg)
{
int temp;
for (int i = 0 ; i < 10000 ; i++)
{
sem_wait(s1);
sem_wait(s0);
temp = count;
sleep(0);
temp--;
sleep(0);
count = temp;
sem_post(s0);
sem_post(s2);
}
}
void *worker2(void *arg)
{
int temp;
for (int i = 0 ; i < 10000 ; i++)
{
sem_wait(s2);
sem_wait(s0);
temp = count;
sleep(0);
temp++;
sleep(0);
count = temp;
sem_post(s0);
sem_post(s1);
}
}
int main(int argc, char *argv[])
{
s0 = sem_open("s0",O_CREAT,0666,1);
s1 = sem_open("s1",O_CREAT,0666,10000);
s2 = sem_open("s2",O_CREAT,0666,0);
pthread_t p1 , p2;
pthread_create(&p1,NULL,worker1,NULL);
pthread_create(&p2,NULL,worker2,NULL);
pthread_join(p1,NULL);
pthread_join(p2,NULL);
sem_close(s0);
sem_close(s1);
sem_close(s2);
sem_unlink("s0");
sem_unlink("s1");
sem_unlink("s2");
printf("%d\n",count);
return 0;
}
