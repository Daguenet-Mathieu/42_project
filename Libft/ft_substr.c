#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*p;

	i = ft_strlen(&s[start]);
	if (i > len)
		i = len;
	p = malloc(sizeof(char) * (i + 1));
	if (!p)
		return (NULL);
	j = 0;
	while (j < i)
	{
		p[j] = s[i + j];
		j++;
	}
	p[j] = '\0';
}
