#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char		*dup;

	i = 0;
	dup = ft_strdup(s);
	if (!dup)
		return (NULL);
	while (s[i])
	{
		f(i, s[i]);
	}
}
