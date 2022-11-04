#include "libft.h"

int	ft_isascii(int c)
{
	int	i;

	i = 0;
	if (c <= 127 && c >= 0)
		i = 1;
	return (i);
}
