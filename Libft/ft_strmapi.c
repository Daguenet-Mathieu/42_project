/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madaguen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:34:13 by madaguen          #+#    #+#             */
/*   Updated: 2022/11/22 20:37:00 by madaguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*dup;

	if (!f || !s)
		return (NULL);
	i = 0;
	dup = ft_strdup(s);
	if (!dup)
		return (NULL);
	while (dup[i])
	{
		dup[i] = f(i, s[i]);
		i++;
	}
	return (dup);
}
