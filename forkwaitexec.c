#include "header.h"
int main(void)
{
	pid_t pid;
	char *buf;
	size_t size;
	char *pathname = getcwd(buf, size); /* gets full path of current directory*/
	char *const args[] = {"/bin/ls", "-l", pathname, NULL};
	char *const envp[] = {NULL};
	int i;

	pid = fork();
	if (pid < 0)
		perror("Fork failure");
	if (pid == 0)
	{
		if (execve(args[0], args, envp) == -1)
			perror("Execve failure");
	}
	else
	{
		wait(NULL);
	}
return (0);
}
