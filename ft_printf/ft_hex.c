/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madaguen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:55:55 by madaguen          #+#    #+#             */
/*   Updated: 2022/11/24 15:57:20 by madaguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex(unsigned long long n, int maj)
{
	int	i;

	i = 0;
	if (n >= 16)
		i += ft_hex(n / 16, maj);
	if (n % 16 < 10)
		i += ft_putchar(n % 16 + 48);
	else
	{
		if (maj)
			i += ft_putchar((n % 16) - 10 + 'A');
		else
			i += ft_putchar((n % 16) - 10 + 'a');
	}
	return (i);
}
