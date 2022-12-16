/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madaguen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:58:28 by madaguen          #+#    #+#             */
/*   Updated: 2022/11/28 20:14:57 by madaguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	while (format[i])
	{
		if (format[i] != '%')
			len += ft_putchar(format[i]);
		else if (format[i + 1] && format[i] == '%' && isinchar(format[i + 1]))
			len += handdle_letter(format[1 + i++], args);
		else
			len += ft_putchar(format[i]);
		if (len == -1)
			return (-1);	
		i++;
	}
	va_end(args);
	return (len);
}
