#include "libft.h"

int	ft_isdigit(int c)
{
	int	i;
	i = 0;

	if (c <= '9' && c >= '0')
		c = 1;
	return (i);
}
