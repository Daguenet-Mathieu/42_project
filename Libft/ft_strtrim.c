/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madaguen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:35:38 by madaguen          #+#    #+#             */
/*   Updated: 2022/11/17 21:02:58 by madaguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_is_in_set(char c, char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	get_size(char const *s1, char const *set, int *i, int *j)
{
	int	size;

	*i = 0;
	*j = ft_strlen(s1);
	while (s1[*i] && ft_is_in_set(s1[*i], (char *)set))
		(*i)++;
	while (*j >= 0 && ft_is_in_set(s1[*j - 1], (char *) set))
		(*j)--;
	if (*i >= *j)
		size = 0;
	else
		size = *j - *i;
	return (size);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		c;
	int		size;
	char	*s2;
	int		i;
	int		j;

	c = 0;
	if (!s1 || !set)
		return (NULL);
	size = get_size(s1, set, &i, &j);
	s2 = malloc(sizeof(char) * (size + 1));
	if (!s2)
		return (NULL);
	if (size < 0)
	{
		s2[c] = '\0';
		return (s2);
	}
	while (i < j)
		s2[c++] = s1[i++];
	s2[c] = '\0';
	return (s2);
}
