#include <stdio.h>
#include <pthread.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>
sem_t *s1 , *s2 , *s3 , *s4 , *ss1 , *ss2 , *ss3 , *ss4;
void *work1(void *arg)
{
while (1)
{
sem_wait(ss1);
sem_wait(s2);
//proccess1
sem_post(s1);
sem_post(ss2);
}
return NULL;
}
void *work2(void *arg)
{
while (1)
{
sem_wait(ss2);
sem_wait(s3);
//proccess2
sem_post(s2);
sem_post(ss3);
}
return NULL;
}
void *work3(void *arg)
{
while (1)
{
sem_wait(ss3);
sem_wait(s4);
//proccess3
sem_post(s3);
sem_post(ss4);
}
return NULL;
}
void *work4(void *arg)
{
while (1)
{
sem_wait(ss4);
sem_wait(s1);
//proccess4
sem_post(s4);
sem_post(ss1);
}
return NULL;
}
int main(int argc, char *argv[])
{
pthread_t p1 , p2 , p3 , p4;
s1 = sem_open("s1",O_CREAT,0666,0);
ss1 = sem_open("ss1",O_CREAT,0666,3);
s2 = sem_open("s2",O_CREAT,0666,3);
ss2 = sem_open("ss2",O_CREAT,0666,0);
s3 = sem_open("s3",O_CREAT,0666,2);
ss3 = sem_open("ss3",O_CREAT,0666,0);
s4 = sem_open("s4",O_CREAT,0666,2);
ss4 = sem_open("ss4",O_CREAT,0666,0);
pthread_create(&p1,NULL,work1,NULL);
pthread_create(&p2,NULL,work2,NULL);
pthread_create(&p3,NULL,work3,NULL);
pthread_create(&p4,NULL,work4,NULL);
pthread_join(p1,NULL);
pthread_join(p2,NULL);
pthread_join(p3,NULL);
pthread_join(p4,NULL);
sem_close(s1);
sem_close(ss1);
sem_close(s2);
sem_close(ss2);
sem_close(s3);
sem_close(ss3);
sem_close(s4);
sem_close(ss4);
sem_unlink("s1");
sem_unlink("ss1");
sem_unlink("s2");
sem_unlink("ss2");
sem_unlink("s3");
sem_unlink("ss3");
sem_unlink("s4");
sem_unlink("ss4");
return 0;
}
