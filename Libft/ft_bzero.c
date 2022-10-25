#include "libft.h"

void bzero(void *s, size_t n)
{
	int	i;
	char	*ps;

	i = 0;
	ps = (char *) s;
	while (i < n)
	{
		ps[i] = 0;
		i++;
	}
}
