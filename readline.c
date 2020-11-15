#include "header.h"
int main(void)
{
	size_t bufsize;
	char *buffer;

	printf("$ ");
	getline(&buffer, &bufsize, stdin);
	printf("%s", buffer);
return (0);
}
