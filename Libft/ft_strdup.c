#include "libft.h"

char	*strdup(const char *s)
{
	int	i;
	char	*dst;

	i = 0;
	dst = malloc(sizeof(char)ft_strlen(s) + 1);
	if (!dest)
		return (NULL);
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
