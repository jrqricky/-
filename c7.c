#include <stdio.h>
int main()
{
char msg[] = "Hello World\n";
asm volatile
(
"mov $0xc, %%edx\n\t"
"lea %0, %%ecx\n\t"
"mov $1, %%ebx\n\t"
"mov $0x4, %%eax\n\t"
"int $0x80\n\t"
:
:"m"(msg)
);
return 0;
}
