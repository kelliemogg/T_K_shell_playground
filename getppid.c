#include "header.h"
int main(void)
{
	pid_t myppid;

	myppid = getppid();
	printf("%d\n", myppid);
return (0);
}
