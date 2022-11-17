/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madaguen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:30:20 by madaguen          #+#    #+#             */
/*   Updated: 2022/11/14 21:03:52 by madaguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
