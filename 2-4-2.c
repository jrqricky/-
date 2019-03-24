#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
pid_t fpid;
fpid = fork();
if (fpid != 0) fpid = fork();
else
{
fpid = fork();
if (fpid != 0)
{
fpid = fork();
printf("pid = %d, ppid = %d\n",getpid(),getppid());
sleep(1);
exit(1);
}
}
while (1)
{
printf("pid = %d, ppid = %d\n",getpid(),getppid());
sleep(10);
}
return 0;
}
