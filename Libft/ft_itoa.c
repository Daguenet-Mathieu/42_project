#include "libft.h"

static void	get_neg(char *s, int size, long int *nb)
{
	s[0] = '-';
	if (*nb == -2147483648)
	{
		s[size - 1] = ((*nb % 10) + 48);
		*nb = *nb / 10;
	}
	*nb = *nb * -1;
}

static char	get_nb(long int *nb, int size, char *s)
{
	int	i;

	i = 0;	
	while (*nb > 0)
	{
		s[size - 1 - i] = (*nb % 10) + 48;
		*nb = *nb / 10;
		i++;
	}
}

char	*ft_itoa(int n)
{
	char		*s;
	int		size;
	long int	nb;

	nb = n;
	size = 1;
	if (nb < 0)
	{
		size ++;
		get_neg(s, size, &nb);
	}
	while (nb >= 10)
	{
		size++;
		nb = nb / 10;
	}
	s = malloc(sizeof(char) * (size + 1));
	if (nb == 0)
		s[0] = 0;
	get_nb(&nb, size, s);
	s[size] = '\0';
	return (s);
}
