/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madaguen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:38:26 by madaguen          #+#    #+#             */
/*   Updated: 2022/12/01 17:18:24 by madaguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s1)
{
	int		i;
	char	*dup;

	dup = malloc(ft_strlen(s1) + 1);
	i = 0;
	while (s1[i])
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = 0;
	return (dup);
}

int	verifn(char *buf)
{
	int	i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*divstr(char *buf, char **bufdest, int n)
{
	int	c;
	int	i;
	char	*tmp;
   
	i = 0;
	c = 0;
	tmp = malloc(n + 2);
	while (i <= n)
		tmp[i++] = buf[c++];
	tmp[i] = 0;
	if (!buf[n + 1])
	{
		free(buf);
		return (tmp);
	}
	n = n + 1;
	c = 0;
	while (buf[n])
		(*bufdest)[c++] = buf[n++];
	(*bufdest)[c] = 0;
	free(buf);
	return (tmp);
}

char	*ft_strjoin(char *dest, char **src)
{
	int		i;
	int		c;
	char	*s3;

	c = 0;
	if(!(*dest))
	{
		s3 = ft_strdup(*src);
		free(*src);
		return (s3);
	}
	i = ft_strlen(dest);
	s3 = malloc(i + ft_strlen(*src) + 1);
	while (dest[c])
	{
		s3[c] = dest[c];
		c++;
	}
	c = 0;
	while ((*src)[c])
		s3[i++] = (*src)[c++];
	s3[i] = 0;
	free(*src);
	return (s3);
}

char *get_next_line(int fd)
{
	int			r;
	char		*tmp;
	static char	*buf[BUFFER_SIZE + 1];
	char		*tmp2;
	
	tmp2 = FT_NULL;
	if (verifn(*buf) != -1)
		return(divstr(ft_strdup(*buf), buf, verifn(*buf)));
	while (1)
	{
		tmp = malloc(BUFFER_SIZE + 1);
		if (!tmp)
			return (FT_NULL);
		tmp[BUFFER_SIZE] = 0;
		r = read(fd, tmp, BUFFER_SIZE);
		if (r <= 0)
		{
			free(tmp);
			if((*buf)[0] == 0)
				return (FT_NULL);
			else
				return (ft_strdup(*buf));
		}
		tmp2 = ft_strjoin(*buf, &tmp);
		if (verifn(tmp2) != -1)
			return (divstr(tmp2,  buf,verifn(tmp2)));
	}
}
