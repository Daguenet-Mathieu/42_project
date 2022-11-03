#include "libft.h"

char	*ft_strdup(const char *s)
{
	int	i;
	char	*dest;

	i = 0;
	dest = malloc(sizeof(char) * (ft_strlen(s) + 1));
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

int main(int argc, char **argv)
{
	printf("%s\n", ft_strdup(argv[1]));
}
