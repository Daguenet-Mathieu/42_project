/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madaguen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:36:46 by madaguen          #+#    #+#             */
/*   Updated: 2022/11/17 16:36:27 by madaguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*p;
	
	if (s == NULL || *s == 0)
		return (NULL);
	if (start >= ft_strlen(s))
		i = 0;
	else
		i = ft_strlen(&s[start]);
	if (i > len)
		i = len;
	p = malloc(sizeof(char) * (i + 1));
	if (!p)
		return (NULL);
	j = 0;
	while (j < i)
	{
		p[j] = s[start + j];
		j++;
	}
	p[j] = '\0';
	return (p);
}

/*int main()
{
	char const *s;

	s = strdup("1");
	ft_substr(s, 42, 42000000);
	return (0);
}*/
