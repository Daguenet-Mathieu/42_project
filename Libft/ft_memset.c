#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	int		i;
	unsigned char	*p;
	
	i = 0;
	p = (unsigned char *) s;

	while (i < n)
	{
		p[i] = (unsigned char)c;
		i++;
	}
}
