/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madaguen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:53:18 by madaguen          #+#    #+#             */
/*   Updated: 2022/11/23 15:53:45 by madaguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"


int	ft_putnbr(int nb)
{
	int				i;
	unsigned int	n;

	i = 0;
	if (nb < 0)
	{
		i += ft_putchar('-');
		nb = nb * -1;
	}
	n = nb;
	if (n >= 10 )
		i += ft_putnbr(n / 10);
	i += ft_putchar((n % 10) + 48);
	return (i); 
}
