#include "header.h"
int main(void)
{
        char *prompt = "Enter a command:\n";
        char *oneword = "One word only please\n";
        char *buffer;
        size_t bufsize = 32;
        int runtime;
        int userinput;
        char *exit = "exit"
        pid_t pid;
        char *cwdbuf;
        size_t size;
        char *pathname = getcwd(cwdbuf, size); /* gets full path of current directory*/
        int i;


        buffer = malloc(sizeof(char) * bufsize);
        while (runtime)
        {
                write(STDOUT_FILENO, prompt, stringlength(prompt));
                userinput = getline(&buffer, &bufsize, stdin);
                if (_strcmp(buffer, exit) == 0)
                {
                        break;
                }
        }
free(buffer);
return (0);
}
