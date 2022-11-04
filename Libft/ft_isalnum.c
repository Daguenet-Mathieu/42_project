#include "libft.h"

int	ft_isalnum(int c)
{
	int	i;

	i = 0;
	if (ft_isalpha(c) || ft_isdigit(c))
		i = 1;
	return (i);
}
