/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madaguen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:34:47 by madaguen          #+#    #+#             */
/*   Updated: 2022/11/17 21:26:00 by madaguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *string, int c)
{
	int	i;

	i = ft_strlen(string);
	if (!c)
		return ((char *)&string[i]);
	while (i >= 0)
	{
		if ((unsigned char)string[i] == (unsigned char)c)
			return ((char *)&string[i]);
		i--;
	}
	return (NULL);
}
