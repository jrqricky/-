#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>
sem_t *s1 , *s2 , *s3 , *s0;
int main(int argc, char *argv[])
{
s1 = sem_open("s1",O_CREAT,0666,0);
s2 = sem_open("s2",O_CREAT,0666,0);
s3 = sem_open("s3",O_CREAT,0666,0);
s0 = sem_open("s0",O_CREAT,0666,1);
if (fork() == 0)
{
printf("I am the proccess P1\n");
sem_post(s1);
sem_post(s1);
}
else
{
if (fork() == 0)
{
sem_wait(s1);
sem_wait(s0);
printf("I am the proccess P2\n");
sem_post(s0);
sem_post(s2);
}
else
{
if (fork() == 0)
{
sem_wait(s1);
sem_wait(s0);
printf("I am the proccess P3\n");
sem_post(s0);
sem_post(s3);
}
else
{
if (fork() == 0)
{
sem_wait(s2);
sem_wait(s3);
printf("I am the proccess P4\n");
}
}
}
}
sem_close(s1);
sem_close(s2);
sem_close(s3);
sem_close(s0);
sem_unlink("s1");
sem_unlink("s2");
sem_unlink("s3");
sem_unlink("s0");
return 0;
}
