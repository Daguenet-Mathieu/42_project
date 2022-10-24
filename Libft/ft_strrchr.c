#include "libft.h"

char	*strrchr(const char *string, int searchedChar)
{
	int	i;

	if (!searchedChar)
		return (string);
	i = ft_strlen(string);
	while (i >= 0)
	{
		if (string[i] == searchedChar)
			return (&string[i]);
		i--;
	}
	return (NULL);
}
