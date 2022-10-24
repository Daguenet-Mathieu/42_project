#include "libft.h"

char	*strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!*little)
		return (big);
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] && little[j] && big[i +j] == little[j])
			j++;
		if (!little[j])
			return (&big[i + j]);
		i++;
	}
	return (NULL);
}
