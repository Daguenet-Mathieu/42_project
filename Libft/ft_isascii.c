#include "libft.h"

int	isascii(int c)
{
	int	i;

	i = 0;
	if (c <= 127 && c >= 0)
		i = 1;
	return (i);
}
