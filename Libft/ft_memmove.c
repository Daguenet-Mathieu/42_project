#include "libft.h"

void    *ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	unsigned char	*cdest;
	unsigned char	*csrc;

	i = 0;
	cdest = (unsigned char *) dest;
	csrc = (unsigned char *) src;
	if (csrc < cdest)
	{
		i = n;
		while (i > 0)
		{
			cdest[i - 1] = csrc[i - 1];
			i--;
		}
	}
	else
	{
		while (i < n)
		{
			cdest[i] = csrc[i];
			i++;
		}
	}
	return (dest);
}
