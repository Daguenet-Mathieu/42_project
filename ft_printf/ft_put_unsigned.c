/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madaguen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:55:00 by madaguen          #+#    #+#             */
/*   Updated: 2022/11/23 16:13:19 by madaguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int ft_put_unsigned(unsigned int n)
{
	int	i;

	i = 0;
	if (n >= 10 )
		i += ft_put_unsigned(n / 10);
	i += ft_putchar((n % 10) + 48);
	return (i); 
}
