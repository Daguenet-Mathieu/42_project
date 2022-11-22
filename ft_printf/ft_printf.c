/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madaguen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:58:28 by madaguen          #+#    #+#             */
/*   Updated: 2022/11/22 02:08:44 by madaguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s)
{
	char	*dst;
	char	*tmp;

	dst = malloc(ft_strlen(s));
	if (!dst)
		return (NULL);
	tmp = dst;
	while(*s)
		*tmp++ = *s++;
	return (dst);
}

int	isinchar(char c)
{
	char	*s;
	int		i;

	i = 0;
	s = ft_strdup("cspdiuxX%");
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_hex(unsigned long nb, int maj)
{
	int	i;

	i = 0;
	if (nb >= 16)
		i += ft_hex(nb / 16, maj);
	if (nb % 16 < 10)
		i += ft_putchar(nb % 16 + 48);
	else
	{
		if (maj)
			i += ft_putchar((nb % 16) - 10 + 'A');
		else
			i += ft_putchar((nb % 16) - 10 + 'a');
	}
	return (i);
}

int ft_put_unsigned(unsigned int n)
{
	int	i;

	i = 0;
	if (n >= 10 )
		i += ft_put_unsigned(n / 10);
	i += ft_putchar((n % 10) + 48);
	return (i); 
}

int	ft_putnbr(int nb)
{
	int				i;
	unsigned int	n;

	i = 0;
	if (nb < 0)
	{
		i += ft_putchar('-');
		nb = nb + -1;
	}
	n = nb;
	if (nb >= 10 )
		i += ft_putnbr(n / 10);
	i += ft_putchar((n % 10) + 48);
	return (i); 
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if(!s)
	{
		i += ft_putchar("(nil)");
		return (i);
	}
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

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
		len += ft_hex(va_arg(args, unsigned long), (c == 'X'));
	if (c == 'p')
	{
		p = va_arg(args, unsigned long);
		if (!p)
			return (len += ft_putstr("(nil)"));
		len += write(1 , "0x", 2);
		ft_hex(p, 0);
	}
	if (c == '%')
		len += ft_putchar(c);
	return (len);
}



int	ft_printf(const char *format, ...)
{
	va_list	args;
	int	i;
	int	len;
	
	if (!format)
		return (-1);
	va_start(args, format);
	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] != '%')
			len = len + ft_putchar(format[i]);
		else if (format[i + 1] && format[i] == '%' && isinchar(format[i + 1]))
		{
			len = len + handdle_letter(format[i + 1], args);
			i += 1;
		}
		else
			len = len + ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (len);
}
