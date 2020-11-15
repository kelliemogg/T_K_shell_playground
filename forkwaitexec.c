#include "header.h"
int main(void)
{
	pid_t pid;
	char *const args[] = {"/bin/ls", "-l", "/tmp", NULL};
	char *const envp[] = {NULL};
	int i;

	


	execve(args[0], args, envp);
return (0);
}
