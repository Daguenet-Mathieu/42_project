#include "libft.h"

int	memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n && (unsigned char)s1[i] != (unsigned char)s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
