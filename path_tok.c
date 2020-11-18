#include "header.h"
int main(int argc, char *argv[])
{
	char *prompt = "Enter a command:\n";
	char *oneword = "One word only please\n";
	char *getlinebuffer;
	size_t bufsize = 32;
	char *newline = "\n";
	int runtime;
	int userinput;
	char *exit = "exit";
	char *ls = "ls";
	pid_t pid;
        char *cwdbuffer;
        size_t cwdsize;
        char *pathname = getcwd(cwdbuffer, cwdsize); /* gets full path of current directory*/
        char *const args[] = {"/bin/ls", "-l", pathname, NULL};
        char *const envp[] = {NULL};

	getlinebuffer = malloc(sizeof(char) * bufsize);
	while (runtime)
	{
		write(STDOUT_FILENO, prompt, stringlength(prompt));
		userinput = getline(&getlinebuffer, &bufsize, stdin);
		if (_strchr(getlinebuffer, ' ') != '\0')
		{
			write(STDOUT_FILENO, oneword, stringlength(oneword));
			continue;
		}
		if (_strcmp(getlinebuffer, exit) == 0)
		{
			break;
		}
		if (_strcmp(getlinebuffer, ls) == 0) /*ls implementation with no args*/
		{
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
		}
	}
	free(getlinebuffer);
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

char* _get_env(char *env)
{
	int inner;
	int outer;
	char *env = "PATH";
	char *name;

	for (outer = 0; environ[outer] != NULL; outer++)
	{
		for (inner = 0; environ[inner] != '='; inner++)
		{
			if (environ[outer][inner] != env[inner])
				continue;
			if (environ[outer][inner + 1] == '=')
				return(environ[outer][inner + 2]);
		}
	}
}
