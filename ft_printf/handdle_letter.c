/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handdle_letter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madaguen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:49:32 by madaguen          #+#    #+#             */
/*   Updated: 2022/11/24 17:09:22 by madaguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handdle_letter(char c, va_list args)
{
	int				len;
	unsigned long	p;

	len = 0;
	if (c == 's')
		len += ft_putstr(va_arg(args, char *));
	if (c == 'i' || c == 'd')
		len += ft_putnbr(va_arg(args, int));
	if (c == 'u')
		len += ft_put_unsigned(va_arg(args, unsigned int));
	if (c == 'c')
		len += ft_putchar(va_arg(args, int));
	if (c == 'x' || c == 'X')
		len += ft_hex(va_arg(args, unsigned), (c == 'X'));
	if (c == 'p')
	{
		p = va_arg(args, unsigned long);
		if (!p)
			return (len += ft_putstr("(nil)"));
		len += write(1, "0x", 2);
		len += ft_hex(p, 0);
	}
	if (c == '%')
		len += ft_putchar(c);
	return (len);
}
