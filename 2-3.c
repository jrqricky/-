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
printf("pid = %d, ppid = %d\n",getpid(),getppid());
while (1)
{
}
return 0;
}
