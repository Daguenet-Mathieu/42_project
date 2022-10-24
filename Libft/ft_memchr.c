#include "libft.h"

void *memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while ((unsigned char)s[i] && i < n || !c)
	{
		if ((unsigned char)s[i] == c || !c)
			return (&s[i]);
		i++;
	}
	return (NULL);
}
