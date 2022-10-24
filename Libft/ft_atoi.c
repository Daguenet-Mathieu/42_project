#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 1;
	res = 0;

	while (nptr[i] && (nptr[i] <= 13 && nptr[i] >= 9) || nptr[i] == 32)
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign -= sign;
		i++;
	}
	while (nptr[i] && (nptr[i] <= '9' && nptr[i] >= '0'))
	{
		res = res * 10 + nptr[i] - '0';
		i++;
	}
	return (res * sign);
}
