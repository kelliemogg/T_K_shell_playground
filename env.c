#include "header.h"

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
                                        return(name);
                                }
                        }
                }
        }
        return(NULL);
}

char *_env_parser(char *name)
{
	int token_inc;
	int tokencount;
	char *tokenize;
	int i;
	char **argv;
	const char *linked;

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
				linked = create(tokenize);
				printf("%s\n", argv[token_inc]);
				token_inc++;
			}
		}
		break;
	}
	free(*argv);
}


void create(node **head, node **tail, char **str)
{
	node *new_dir = (node*)malloc(sizeof(node));
	int length = _strlen(*str);

	if (new_dir == NULL)
	{
		printf(stderr, "Error creating new dir\n");
		exit (0);
	}
	new_dir->str = (char *)malloc(sizeof(*str));
	new_dir->str = *str;
	new_word->length = length;
	printf("%s ", new_dir->str);

	return(0);
}
/*
int add_nodes(char *)
{
	struct node *prev, *head, *p;
	int n, i;
	head = NULL;

	for (i = 0; i < n; i++)
	{
		p = malloc(sizeof(struct node));
		p->next = NULL;
		if (head == NULL)
			head = p;
		else
			prev->next = p;
	}
	return (0);
	} */

/* newnode = malloc(sizeof{list_t));
	if (newnode == NULL)
		return (NULL);
	newnode->str;
	for (x = 0; str[x] != '\0'; x++)
		;
	newnode->len = x;
	newnode->next = *head;
	*head = newnode;
	return (*head);
} */


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
