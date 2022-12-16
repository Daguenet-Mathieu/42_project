/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isinchar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madaguen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:58:18 by madaguen          #+#    #+#             */
/*   Updated: 2022/11/24 15:59:50 by madaguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static char	*ft_strdup(char *s)
{
	char	*dst;
	int		i;

	i = 0;
	dst = malloc(ft_strlen(s) + 1);
	if (!dst)
		return (NULL);
	while (s[i])
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = 0;
	return (dst);
}

int	isinchar(char c)
{
	char	*s;
	int		i;

	i = 0;
	s = ft_strdup("cspdiuxX%");
	if (!s)
	{
		free(s);
		return (0);
	}
	while (s[i])
	{
		if (s[i] == c)
		{
			free(s);
			return (1);
		}
		i++;
	}
	free(s);
	return (0);
}
