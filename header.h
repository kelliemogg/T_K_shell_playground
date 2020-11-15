#ifndef HEADER_H
#define HEADER_H

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char _strchr(char *s, char c);
int fork_process(void);
int stringlength(char *s);
char *read_line(void);

char *envp[] =
{
	"HOME=/",
	"PATH=/bin:usr/bin",
	0
};

#endif /* HEADER_H */
