/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madaguen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:27:43 by madaguen          #+#    #+#             */
/*   Updated: 2022/11/07 11:27:46 by madaguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *memchr(const void *s, int c, size_t n)
{
	size_t	i;
	unsigned char	*ps;

	i = 0;
	ps = (unsigned char *) s;
	while (ps[i] && i < n || !c)
	{
		if (ps[i] == c || !c)
			return ((void *)&ps[i]);
		i++;
	}
	return (NULL);
}
