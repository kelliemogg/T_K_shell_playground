#include "header.h"

int main(int argc, char **argv)
{
        shell_loop();
	return (0);
}

void shell_loop(void)
{
        int userinput;
        char **argv;
        char *buffer;
        size_t bufsize = 32;
        char *prompt = "& ";
	int status;

        while (!status)
        {
                buffer = malloc(sizeof(char) * bufsize);
                write(STDOUT_FILENO, prompt, stringlength(prompt));
                userinput = getline(&buffer, &bufsize, stdin);
                argv = tokenize(buffer);
		if (argv != NULL)
		{
			execve();
		}
		free(buffer);
		free(argv);
	}
}


char **tokenize(char *userinput)
{
        int token_inc = 0;
        char *tokenize;
        char **argv;
        int tokencount = 0;
        int i;

        strtok(userinput, "\n");
	for (i = 0; userinput[i] != '\0'; i++)
	{
		if (userinput[i] == ' ')
		{
			tokencount++;
		}
	}
	argv = malloc(8 * (tokencount + 2));
	if (argv != NULL)
	{
		token_inc = 0;
		tokenize = strtok(userinput, " ");
		while (token_inc < (tokencount + 1))
		{
			argv[token_inc] = tokenize;
			tokenize = strtok(NULL, " ");
			printf("%s\n", argv[token_inc]);
			token_inc++;
		}
	}
	return (argv);
}

int forkwaitexec(char **argv)
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
		perror("Fork failure\n");
	if (child_pid == 0)
	{
		execve(argv[0], argv, NULL);
	}
	else
	{
		wait(&status);
	}
	return (1);
}

char *_env_parser(char *name)
{
        int token_inc;
        int tokencount;
        char *tokenize;
        int i;
        char **argv;

        while(name != NULL)
        {
                tokencount = 0;
                for (i = 0; name[i] != '\0'; i++)
                {
                        if (name[i] == ':')
                        {
                                tokencount++;
                        }
                }
                argv = malloc(8 * (tokencount + 1));
                if (argv != NULL)
                {
                        token_inc = 0;
                        tokenize = strtok(name, ":");
                        while (token_inc < (tokencount + 1))
                        {
                                argv[token_inc] = tokenize;
                                tokenize = strtok(NULL, ":");
                                printf("%s\n", argv[token_inc]);
                                token_inc++;
                        }
                }
                break;
        }
        free(*argv);
}

char *_get_env(char *env)
{
        int inner;
        int outer;
        char *name;
        char *parse;

        for (outer = 0; environ[outer] != NULL; outer++)
        {
                for (inner = 0; environ[outer][inner] != '='; inner++)
                {
                        /* printf("%c", environ[outer][inner]); */
                        if (environ[outer][inner] != env[inner])
                                break;
                        if (environ[outer][inner] == env[inner])
                        {
                                if (env[inner + 1] == '\0' && environ[outer][inner + 1] == '=')
                                {
                                        name = _strdup(&(environ[outer][inner + 2]));
                                        parse = _env_parser(name);
                                        return(parse);
                                }
                        }
                }
        }
        return(NULL);
}


/*
int main()
{
        char *path = NULL;

        path = _get_env("PATH");
        printf("%s\n", path);
        return(0);
}*/


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


