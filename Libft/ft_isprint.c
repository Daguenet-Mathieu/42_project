#include "libft.h"

int ft_isprint(int c)
{
	int	i;

	i = 0;
	if (c <= 126 && c >= 32)
		i = 1;
	return (i);
}
