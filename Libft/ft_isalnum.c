#include "libft.h"

int	isalnum(int c)
{
	int	i;

	i = 0;
	if (ft_isalpha(c) || ft_isdigit(c))
		i = 1;
	return (i);
}
