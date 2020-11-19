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
#include <strings.h>

/* new prototypes associated with test.c */

char **tokenize(char *userinput);

int stringlength(char *s);

void shell_loop(void);

/*char *builtin_args[] = {
	"cd",
	"help",
	"exit"
};

int (*builtin_func[] (char **)) = {
	&_cd,
	&_home,
	&_exit
};*/
/* new prototypes associated with test.c*/

char _strchr(char *s, char c);
int fork_process(void);
char *read_line(void);
char *read_command(void);
int execute_cmd(char **args);
void _status_on(void);
int command_i(void);

/* prototypes for env and parsing env */
typedef struct node
{
        char *str;
        struct node *next;
} node;
char *_strdup(char *str);
char *_env_parser(char *name);
char *_get_env(char *env);
extern char **environ;
void create(node **head, node **tail, char **str);

typedef struct commander
{
	char *commad;
	void (*cmd_func)();
} commander;

#endif /* HEADER_H */
