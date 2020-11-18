#include "header.h"

int main(void)
{
	char *buffer;
	size_t bufsize = 1024;
	int userinput;
	char *prompt = "$ ";
	char *exit = "exit";

	int token_inc = 0;
	char *tokenize;
	char **argv;
	int tokencount;
	int i;
	int j;

	pid_t pid;

	buffer = malloc(sizeof(char) * bufsize);
	while (1)
	{
		tokencount = 0;
		write(STDOUT_FILENO, prompt, stringlength(prompt));
		userinput = getline(&buffer, &bufsize, stdin);
		strtok(buffer, "\n");
		for (i = 0; buffer[i] != '\0'; i++)
		{
			if (buffer[i] == ' ')
			{
				tokencount++;
			}
		}
		argv = malloc(8 * (tokencount + 2));
		if (argv != NULL)
		{
			token_inc = 0;
			tokenize = strtok(buffer, " ");
			while (token_inc < (tokencount + 1))
			{
				argv[token_inc] = tokenize;
				tokenize = strtok(NULL, " ");
				printf("%s\n", argv[token_inc]);
				token_inc++;
			}
			if (argv[0] != NULL)
			{

			}
		}
	}
free(buffer);
free(*argv);
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


int _strcmp(char *s1, char *s2)
{
        for (; *s1 != '\0' && *s2 != '\0'; s1++, s2++)
        {
                if (*s1 != *s2)
                {
                        return (*s1 - *s2);
                }
        }
	return (0);
}

char _strchr(char *s, char c)
{
        int i;

        for (i = 0; s[i] >= '\0'; i++)
        {
                if (s[i] == c)
                {
                        return (1);
                }
        }
	return ('\0');
}
int stringlength(char *s)
{
        int i;

        for (i = 0; s[i] != '\0'; i++)

	{}
	return (i);
}

int  _get_env(char *env)
{
	int inner;
	int outer;

	for (outer = 0; environ[outer] != NULL; outer++)
	{
		for (inner = 0; environ[outer][inner] != '='; inner++)
		{
			if (environ[outer][inner] != env[inner])
				continue;
			if (environ[outer][inner + 1] == '=')
				return(environ[outer][inner + 2]);
		}
	}
}
