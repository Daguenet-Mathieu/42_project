/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madaguen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 02:47:49 by madaguen          #+#    #+#             */
/*   Updated: 2022/12/03 16:59:43 by madaguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	ft_strlen(char *s1)
{
	int	i;

	i = 0;
	while (s1[i])
		i++;
	return (i);
}

int	verifn(char *buf)
{
	int	i;

	i = 0;
	if (!buf)
		return (-1);
	while (buf[i])
	{
		if (buf[i] == '\n')
			return (i);
		i++;
	}
	return -1;
}

char	*ft_divstr(char **buf, int i)
{
	int		c;
	char	*tmp;
	char	*tmp2;
	c = 0;
	tmp = malloc(i + 2);
	while (c <= i)
	{
		tmp[c] = (*buf)[c];
		c++;
	}
	tmp[c] = 0;
	if (!(*buf)[i + 1])
	{
		free(*buf);
		return (tmp);
	}
	i = i + 1;
	c = 0;
	tmp2 = malloc(ft_strlen(buf[i]) + 1);
	while ((*buf)[i])
		tmp2[c++] = (*buf)[i++];
	tmp2[c] = 0;
	free(*buf);
	*buf = tmp2;
	return (tmp);
}

char	*ft_join(char *s1, char *s2)
{
	int		size;
	char	*s3;
	int		c;
	int		i;
	if (!s1)
	{
		s3 = malloc(ft_strlen(s2));
		return (s3);
	}
	size = ft_strlen(s1) + ft_strlen(s2);
	s3 = malloc(size + 1);
	c = 0;
	i = 0;
	while (s1[i])
		s3[c++] = s1[i++];
	i = 0;
	while (s2[i])
		s3[c++] = s2[i++];
	s3[c] = 0;
	free(s1);
	free(s2);
	return (s3);
}

void	*ft_free(char **buf)
{
	free(*buf);
	return (FT_NULL);
}

char	*ft_loop(char *tmp, char **buf, int r, int fd)
{
	while (r)
	{
		tmp = malloc(BUFFER_SIZE + 1);
		if (!tmp)
			return (FT_NULL);
		tmp[BUFFER_SIZE] = 0;
		r = read(fd, tmp, BUFFER_SIZE);
		printf("%s",tmp);
		buf[fd] = ft_join(buf[fd], tmp);
		if (r < 0)
			return (ft_free(buf));
		if (r == 0)
		{
			if (buf[fd] && buf[fd][1] != 0)
				return (ft_divstr(&buf[fd], verifn(buf[fd])));
			if (verifn(buf[fd]) != -1)
				return (ft_divstr(&buf[fd], verifn(buf[fd])));
		}
	}
	return ((char*)FT_NULL);
}

char *get_next_line(int fd)
{
	int			r;
	static char	*buf[1024];
	char		*tmp;
	
	r = 1;
	tmp = FT_NULL;
	if (!buf[fd])
	{
		buf[fd] = malloc(BUFFER_SIZE + 1);
		r = read(fd, buf[fd], BUFFER_SIZE);
		if (r <= 0)
		{
			free(buf[fd]);
			return (FT_NULL);
		}
		else
		{
			if (verifn(buf[fd]))
				return (ft_divstr(&buf[fd], verifn(buf[fd])));
		}
	}
	if (fd < 0 || BUFFER_SIZE < 1)
		return (FT_NULL);
	if (buf[fd] && verifn(buf[fd]) != -1)
		return (ft_divstr(&buf[fd], verifn(buf[fd])));
	return (ft_loop(tmp, &buf[fd], r, fd));
}
