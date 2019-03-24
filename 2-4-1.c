#include <unistd.h>
#include <stdio.h>
int main()
{
pid_t fpid;
fpid = fork();
if (fpid != 0) fpid = fork();
else
{
fpid = fork();
if (fpid != 0) fpid = fork();
}
while (1)
{
printf("pid = %d, ppid = %d\n",getpid(),getppid());
sleep(20);
}
return 0;
}
