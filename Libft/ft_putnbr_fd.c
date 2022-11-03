#include "libft.h"

void ft_putnbr_fd(int n, int fd)
{
	unsigned int	nb;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = n * -1;
	}
	nb = n;
	if (nb >= 10)
		ft_putnbr_fd((nb / 10), fd);
	ft_putchar_fd((nb % 10 + 48) , fd);
}

int main ()
{
	int	n = -150;
	ft_putnbr_fd(-150, 1);
	write (1, "\n", 1);
}
