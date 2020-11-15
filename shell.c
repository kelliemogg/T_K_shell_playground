#include "header.h"

int read_command(void)
{
        char *prompt = "Enter a command:\n";
        char *oneword = "One word only please\n";
        char *buffer;
        size_t bufsize = 32;
        char *newline = "\n";
        int runtime;
        int userinput;
        char *exit = "exit";
        char *pups = "puppies";
	char *argv[] = {};
        buffer = malloc(sizeof(char) * bufsize);

	execve("/bin/ls", argv, NULL);

/*        while (1)
        {
                write(STDOUT_FILENO, prompt, stringlength(prompt));
                userinput = getline(&buffer, &bufsize, stdin);
                if (_strchr(buffer, ' ') != '\0')
                        write(STDOUT_FILENO, oneword, stringlength(oneword));
                if (_strcmp(buffer, pups) == 0)
                        puppies();
                if (_strcmp(buffer, exit) == 0)
                {
                        break;
                }

      }
*/free(buffer);
	return (0);
}

int stringlength(char *s)
{
        int i;
        for (i = 0; s[i] != '\0'; i++)
        {}
	return (i);
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

int puppies(void)
{
        printf("Puppies!\n");
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
		if (execve(*argv, argv, NULL) < 0)
			printf("what's up");
		{
			printf("Error: exec failed\n");
			exit(1);
		}
	}
	else
	{
		while (wait(&status) != pid)
			;
	}
}
