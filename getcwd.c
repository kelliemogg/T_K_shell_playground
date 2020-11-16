#include "header.h"
int main(void)
{
	char *buf;
	char *ptr;
	size_t size = 100;

	ptr = getcwd(buf, size);
	printf("%s\n", buf);
}
