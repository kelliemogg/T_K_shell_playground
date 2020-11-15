#include "header.h"
int main(void)
{
	char s[] = "He turns himself into a pickle";
	int i = 0;
	char *token = strtok(s, " ");
	char *array[1];
	int j = 0;

	while (token != NULL)
	{
		array[i] = token;
		i++;
		token = strtok(NULL, " ");
		j++;
	}
	for (i = 0; i < j; i++)
		printf("%s\n", array[i]);
return (0);
}
