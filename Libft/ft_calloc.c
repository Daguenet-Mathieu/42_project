#include "libft.h"

void *ft_calloc(size_t nmemb, size_t size);
{
	void	*p;
	size_t	i;

	i = 0;
	p = malloc(nmemb * size);
	if (!p)
		return (NULL);
	while (i < nmemb * size)
	{
		p[i] = 0;
		i++;
	}
	return (p);
}
