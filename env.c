#include "header.h"

char *_env_parser(char *name)
{
	int token_inc;
	int tokencount;
	char *tokenize;
	int i;
	char **argv;

	while(name != NULL)
	{
		tokencount = 0;
		for (i = 0; name[i] != '\0'; i++)
		{
			if (name[i] == ':')
			{
				tokencount++;
			}
		}
		argv = malloc(8 * (tokencount + 1));
		if (argv != NULL)
		{
			token_inc = 0;
			tokenize = strtok(name, ":");
			while (token_inc < (tokencount + 1))
			{
				argv[token_inc] = tokenize;
				tokenize = strtok(NULL, ":");
				printf("%s\n", argv[token_inc]);
				token_inc++;
			}
		}
		break;
	}
	free(*argv);
}

char *_get_env(char *env)
{
        int inner;
        int outer;
	char *name;
	char *parse;

        for (outer = 0; environ[outer] != NULL; outer++)
        {
                for (inner = 0; environ[outer][inner] != '='; inner++)
		{
			/* printf("%c", environ[outer][inner]); */
                        if (environ[outer][inner] != env[inner])
                                break;
			if (environ[outer][inner] == env[inner])
			{
				if (env[inner + 1] == '\0' && environ[outer][inner + 1] == '=')
				{
					name = _strdup(&(environ[outer][inner + 2]));
					parse = _env_parser(name);
					return(parse);
				}
			}
		}
	}
	return(NULL);
}



int main()
{
	char *path = NULL;

	path = _get_env("PATH");
	/* printf("%s\n", path); */
	return(0);
}

char *_strdup(char *str)
{
	char *duplicate;
	int i;
	int len = 0;

	if (str == NULL)
		return (NULL);

	for (len = 0; str[len] != '\0'; len++)
		;
	duplicate = malloc((len + 1) * sizeof(char));

	if (duplicate == NULL)
		return (NULL);

	for (i = 0; str[i] != '\0'; i++)
		duplicate[i] = str[i];


	return (duplicate);
}
