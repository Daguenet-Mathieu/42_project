#include "libft.h"

int ft_isalpha(int c)
{
	int	i;
	i = 0;
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		i = 1;
	return (i);
}
