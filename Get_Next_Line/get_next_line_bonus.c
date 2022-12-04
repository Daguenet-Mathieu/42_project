/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madaguen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 17:01:33 by madaguen          #+#    #+#             */
/*   Updated: 2022/12/04 05:32:59 by madaguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	verifn(char *str)
{
	int	i;
	
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_divstr(char **str, int i)
{
	char	*s;
	char	*tmp;
	int		c;
	int		j;
	char	*buf;
	c = 0;
	j = 0;
	buf = *str;
	s = malloc(i + 2);
	if (!s)
		return (NULL);
	while (j <= i)
		s[c++] = (*str)[j++];
	s[c] = 0;
	c = 0;
	tmp = malloc(ft_strlen(&buf[i + 1]) + 1);
	if (!tmp)
		return (NULL);
	while ((*str)[j])
		tmp[c++] = (*str)[j++];
	tmp[c] = 0;
	free(*str);
	*str = tmp;
	return (s);
}

char	*ft_strjoin(char **s1, char *s2)
{
	char	*dst;
	int		i;
	int		c;

	c = 0;
	i = 0;
	dst = malloc(ft_strlen(*s1) + ft_strlen(s2) + 1);
	if (!dst)
		return (NULL);
	while ((*s1)[i])
		dst[c++] = (*s1)[i++]; 
	 i = 0;
	 while (s2[i])
		 dst[c++] = (*s1)[i++];
	 dst[c] = 0;
	 free(*s1);
	 *s1 = NULL;
	 free(s2);
	 return (dst);
}

char	*ft_strdup(char **str)
{
	char	*tmp;
	int		i;

	i = 0;
	if (!*str)
		return (NULL);
	tmp = malloc(ft_strlen(*str) + 1);
	if (!tmp)
		return (NULL);
	while ((*str)[i])
	{
		tmp[i] = (*str)[i];
		i++;
	}
	tmp[i] = 0;
	free(*str);
	*str = NULL;
	return (tmp);
}

char	*ft_read(char **buf, int fd)
{
	int		r;
	char	*tmp;

	while (1)
	{
		tmp = malloc(BUFFER_SIZE + 1);
		if (!tmp)
			return (NULL);
		r = read(fd, tmp, BUFFER_SIZE);
		if (r <= 0)
			return (ft_strdup(buf));
		*buf = ft_strjoin(buf, tmp);
		if (verifn(*buf))
			return (ft_divstr(buf, verifn(*buf)));
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*buf[1024];
	int		r;

	if (fd < 0 || fd > 1024)
		return (NULL);
	if (!buf[fd])
	{
		buf[fd] = malloc(BUFFER_SIZE + 1);
		if (!buf[fd])
			return (NULL);
	   	r = read(fd, buf[fd], BUFFER_SIZE);
		if (r <= 0)
		{
			free(buf[fd]);
			return (NULL);
		}
		buf[fd][r] = 0;
		if (r < BUFFER_SIZE && verifn(buf[fd]) == -1)
			return (ft_strdup(&buf[fd]));
	}
	if (verifn(buf[fd]) != -1)
		return (ft_divstr(&buf[fd], verifn(buf[fd])));
	return (ft_read(&buf[fd], fd));
}
