#include "header.h"

int main(void)
{
	char *line;
	char **args;
	int status;
	do {
		printf("$ ");
		line = read_command();
		args = tokenizer();
		status = execute_cmd();

		free (line); /*unsure why*/
		free (args); /* unsure why*/
	} while (status);
}

char *read_command(void)
{
        size_t bufsize = 0;
        char *line = NULL;

	if (getline(&bufsize, &line, stdin))
	{
		if (feof(stdin)) /* Or if getline gets to the null byte */
			exit(EXIT_SUCCESS);
		else
			perror("readline");
		exit(EXIT_FAILURE);
	}
	return(line);
}

char *tokenizer()
{
	char *buf ="abc qwe ccd";
	int i = 0;
	char *p = strtok (buf, " ");
	char *array[3];

	while (p != NULL)
	{
		array[i++] = p;
		p = strtok (NULL, " ");
	}

	for (i = 0; i < 3; ++i)
		printf("%s\n", array[i]);

	return 0;
}

char *execute_cmd();
{
	pid_t pid;
	char *const args[] = {"/bin/ls", "-l", "/tmp", NULL};
	char *const envp[] = {NULL};
	int i;

	execve(args[0], args, envp);
	return (0);
}

int process_id(int argc, char **argv)
{
	int i = 0;
	pid_t pid = fork();
	int status;

	if (pid < 0)
	{
		printf("Error: fork failed.");
		exit (1);
	}
	else if (pid == 0)
	{
		printf("hello");
		if (execve(*argv, argv, NULL))
			exit(1);
		}
	}
	else
	{
		while (wait(&status) != pid)
			;
	}
}
