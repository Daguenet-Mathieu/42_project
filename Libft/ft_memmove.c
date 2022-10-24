#include "libft.h"

void    *ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (src < dst)
	{
		i = n - 1;
		while (i >= 0)
		{
			(char)dest[i] = (char)src[i];
			i--;
		}
	}
	else
	{
		while (i < n)
		{
			(char)dest[i] = (char)src[i];
			i++;
		}
	}
	return (dest);
}
