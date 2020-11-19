#include "header.h"
int main(void)
{
	/*CLI variables*/
	char *buffer;
	size_t bufsize = 1024;
	int userinput;
	char *prompt = "Enter a command: ";
	char *exit = "exit";
	/*tokenizer variables*/
	int token_inc = 0;
	char *tokenize;
	char **argv;
	int tokencount;
	int i;
	int j;
	/*execve variables*/
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
			if (token_inc == 1)
				break;
		}
	}

free(buffer);
free(argv);
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
