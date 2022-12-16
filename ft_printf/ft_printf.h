/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madaguen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 23:25:46 by madaguen          #+#    #+#             */
/*   Updated: 2022/11/23 23:26:24 by madaguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>

int	handdle_letter(char c, va_list args);
int	ft_putstr(char *s);
int	ft_putnbr(int nb);
int	ft_put_unsigned(unsigned int n);
int	ft_hex(unsigned long long n, int maj);
int	ft_putchar(char c);
int	isinchar(char c);
int	ft_printf(const char *format, ...);

#endif
