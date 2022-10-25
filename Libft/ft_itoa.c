#include "libft.h"

char	*ft_itoa(int n)
{
	char	*s;
	int	size;

	if (n < 10)
		size = 1;
	while (n >= 0)
	{
		size++;
		n = n / 10;
	}
	s = malloc(sizeof(char) * (size + 1));
	s[size] = '\0';
	if (n == 0)
	{
		s[0] = 0;
		return (s);
	}
	while (n > 0)
	{
		s[size - 1] = (n % 10) + 48;
		n = n / 10;
	}
	return (s);
}
