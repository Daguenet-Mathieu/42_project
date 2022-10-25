#include "libft.h"

char	*strrchr(const char *string, int searchedChar)
{
	int	i;

	if (!searchedChar)
		return ((char *)string);
	i = ft_strlen(string);
	while (i >= 0)
	{
		if (string[i] == searchedChar)
			return ((char*)&string[i]);
		i--;
	}
	return (NULL);
}
