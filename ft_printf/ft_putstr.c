/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madaguen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:50:52 by madaguen          #+#    #+#             */
/*   Updated: 2022/11/23 20:57:26 by madaguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putstr(char *s)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if(!s)
	{
		len += ft_putstr("(null)");
		return (len);
	}
	while (s[i])
	{
		len += write(1, &s[i], 1);
		i++;
	}
	return (len);
}
