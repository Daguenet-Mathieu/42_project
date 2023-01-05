#include <stddef.h>

void	test(char **j)
{
	char *t;
	t = NULL;
	*j = t;
}

int main()
{
	char *j;
	j = malloc(1);
	printf("%p", j);
	test(&j);
	printf("%p", j);
}
