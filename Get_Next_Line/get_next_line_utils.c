
#include "get_next_line.h"

char	*ft_calloc(size_t size)
{
	char		*tmp;
	size_t		i;

	if (size == 0)
		return (NULL);
	i = 0;
	tmp = malloc(size);
	if (!tmp)
		return (NULL);
	while (i < size)
		tmp[i++] = 0;
	return (tmp);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	verifn(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}
