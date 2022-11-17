/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madaguen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:27:43 by madaguen          #+#    #+#             */
/*   Updated: 2022/11/17 20:27:23 by madaguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ps;

	i = 0;
	ps = (unsigned char *) s;
	while ((i < n))
	{
		if (ps[i] == (unsigned char)c)
			return (&ps[i]);
		i++;
	}
	return (NULL);
}
