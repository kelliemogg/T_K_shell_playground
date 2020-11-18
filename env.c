#include "header.h"

void* _get_env(char *env)
{
        int inner;
        int outer;
	char *name;

        for (outer = 0; environ[outer] != NULL; outer++)
        {
                for (inner = 0; environ[outer][inner] != '='; inner++)
		{
			printf("%c", environ[outer][inner]);
                        if (environ[outer][inner] != env[inner])
                                continue;
			if ((environ[outer][inner] == env[inner]) && (environ[outer][inner] != '='))
			name += environ[outer][inner];
			if (environ[outer][inner + 1] == '=')
				return((void *)environ[outer][inner + 2]);
                }
		printf("\n");
        }
	return (0);
}

int main()
{
	printf("%p", (void *)_get_env("PATH"));
	return(0);
}
