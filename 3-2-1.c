#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
int count = 10000;
void *worker1(void *arg)
{
int temp;
for (int i = 0 ; i < 10000 ; i++)
{
temp = count;
sleep(0);
temp--;
sleep(0);
count = temp;
}
}
void *worker2(void *arg)
{
int temp;
for (int i = 0 ; i < 10000 ; i++)
{
temp = count;
sleep(0);
temp++;
sleep(0);
count = temp;
}
}
int main(int argc, char *argv[])
{
pthread_t p1 , p2;
pthread_create(&p1,NULL,worker1,NULL);
pthread_create(&p2,NULL,worker2,NULL);
pthread_join(p1,NULL);
pthread_join(p2,NULL);
printf("%d\n",count);
return 0;
}
