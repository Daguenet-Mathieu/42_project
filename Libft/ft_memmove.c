#include "libft.h"

void    *ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*pdest;
	char	*psrc;

	i = 0;
	pdest = (char *) dest;
	psrc = (char *) src;
	if (psrc < pdest)
	{
		i = n - 1;
		while (i >= 0)
		{
			pdest[i] = psrc[i];
			i--;
		}
	}
	else
	{
		while (i < n)
		{
			pdest[i] = psrc[i];
			i++;
		}
	}
	return (dest);
}
