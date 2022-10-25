#include "libft.h"

size_t	strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	slen;

	i = 0;
	slen = ft_strlen(src);
	while (src[i] && i < (size - 1))
	{
		dest[i] = src [i];
		i++;
	}
	dest[i] = '\0';
	return (slen);
}
