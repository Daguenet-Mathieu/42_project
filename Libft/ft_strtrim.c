#include "libft.h"

static int	ft_is_in_set(char c, char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
		       return (1);
		i++;	
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	c;
	char	*s2;

	i = 0;
	j = ft_strlen(s1) - 1;
	c = 0;
	while (ft_is_in_set(s1[i], (char*)set))
		i++;
	while (ft_is_in_set(s2[j], (char*) set))
		j--;
	s2 = malloc(sizeof(char) * ((j - i + 1) + 1));
	while (i <= j)
	{
		s2[c] = s1[i];
		c++;
		i++;	
	}
	s2[c] = '\0';
	return (s2);
}
