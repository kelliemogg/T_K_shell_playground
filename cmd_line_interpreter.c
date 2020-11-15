#include "header.h"
int main(void)
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

	buffer = malloc(sizeof(char) * bufsize);
	while (runtime)
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
free(buffer);
return (0);
}
int stringlength(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{}
return (i);
}
/**
*_strcmp- entry point
*description: compares the lengths of two strings
*@s1: a string
*@s2: a string
*Return: negative int, positive int, or 0
**/
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
