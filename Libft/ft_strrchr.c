/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madaguen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:34:47 by madaguen          #+#    #+#             */
/*   Updated: 2022/11/08 15:07:28 by madaguen         ###   ########.fr       */
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
		if (string[i] == c)
			return ((char*)&string[i]);
		i--;
	}
	return (NULL);
}
