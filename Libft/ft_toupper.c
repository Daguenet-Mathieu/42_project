#include "libft.h"

int	toupper(int c)
{
	if (c <= 'z' && c >= 'a')
		c -= 32;
	return (c);
}
