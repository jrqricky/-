#include <unistd.h>
#include <stdio.h>
int main()
{
pid_t fpid;
fpid = fork();
if (fpid == 0)
{
int ret = execl("/usr/bin/vi","vi","/home/jin/桌面/test2/2-1.text",NULL);
if (ret == -1) perror("execl");
}
else
{
while (1)
{
}
}
return 0;
}
