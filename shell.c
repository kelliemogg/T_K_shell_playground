#include "header.h"

int main(void)
{
	char *line;
	char **args;
	int status;
	do {
		printf("$ ");
		line = read_command();
		*args = tokenizer();

		free (line); /*unsure why*/
		free (args); /* unsure why*/
	} while (status);
}

char *read_command(void)
{
        size_t bufsize = 0;
        char *line = NULL;

	if (getline(&line, &bufsize, stdin))
	{
		if (feof(stdin)) /* Or if getline gets to the null byte */
			exit(EXIT_SUCCESS);
		else
			perror("readline");
		exit(EXIT_FAILURE);
	}
	return(line);
}

char *tokenizer(void)
{
	char *buf = "commands and stuff";
	int i = 0;
	int j = 0;
	char *token = strtok (buf, " ");
	char *array[3];

	while (token != NULL)
	{
		array[i] = token;
		i++;
		token = strtok (NULL, " ");
		j++;
	}

	for (i = 0; i < j; i++)
		printf("%s\n", array[i]);
	return 0;
}

int execute_cmd(char **args)
{
	pid_t pid;
	char *const str[] = {"/bin/ls", "-l", "/tmp", NULL};
	char *const envp[] = {NULL};
	int i;

	execve(args[0], str, envp);
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
	else
	{
		while (wait(&status) != pid)
			;
	}
}
