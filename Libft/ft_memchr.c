#include "libft.h"

void *memchr(const void *s, int c, size_t n)
{
	size_t	i;
	unsigned char	*ps;

	i = 0;
	ps = (unsigned char *) s;
	while (ps[i] && i < n || !c)
	{
		if (ps[i] == c || !c)
			return ((void *)&ps[i]);
		i++;
	}
	return (NULL);
}
