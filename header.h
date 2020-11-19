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

/* new prototypes associated with test.c */

char **tokenize(char *userinput);
int stringlength(char *s);
void shell_loop(void);
/* new prototypes associated with test.c*/

char *_get_env(char *env);
char _strchr(char *s, char c);
int fork_process(void);
char *read_line(void);
char *read_command(void);
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
