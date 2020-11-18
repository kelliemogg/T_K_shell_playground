#ifndef HEADER_H
#define HEADER_H

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <errno.h>

char *_get_env(char *env);
char _strchr(char *s, char c);
int fork_process(void);
int stringlength(char *s);
char *read_line(void);
char *read_command(void);
int tokenizer(char *);
int execute_cmd(char **args);
extern char **environ;
void _status_on(void);
int command_i(void);

char *envp[] =
{
	"HOME=/",
	"PATH=/bin:usr/bin",
0
};

typedef struct commander
{
	char *commad;
	void (*cmd_func)();
} commander;

#endif /* HEADER_H */
