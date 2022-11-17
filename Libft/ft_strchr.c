/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madaguen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:31:28 by madaguen          #+#    #+#             */
/*   Updated: 2022/11/17 14:54:11 by madaguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *string, int c)
{
	int	i;

	i = 0;
	while (string[i])
	{
		if ((unsigned char)c == (unsigned char)string[i])
			return ((char *)&string[i]);
		i++;
	}
	if (!c)
		return ((char *)&string[i]);
	return (NULL);
}
