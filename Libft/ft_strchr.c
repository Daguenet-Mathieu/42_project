#include "libft.h"

char	*strchr(const char *string, int searchedChar)
{
	int	i;

	i = 0;
	while (string[i] || !searchedChar)
	{
		if (string[i] == searchedChar || !searchedChar)
			return (&string[i]);
		i++;
	}
	return (NULL);
}
