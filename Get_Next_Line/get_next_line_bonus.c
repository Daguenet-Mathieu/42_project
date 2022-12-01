/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madaguen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 02:47:49 by madaguen          #+#    #+#             */
/*   Updated: 2022/11/30 23:07:21 by madaguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	i = i + 1;
	c = 0;
	tmp = malloc(i + 1);
	while (c < i)
		tmp[c] = (*buf)[c];
	tmp[c] = 0;
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

	size = ft_strlen(s1) + ft_strlen(s2);
	s3 = malloc(size + 1);
	c = -1;
	i = 0;
	while (s1[++c])
		s3[c] = s1[c];
	while (s2[c])
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
		if (r <= 0)
		{
			if (buf[fd] && buf[fd][0] != 0)
				return (ft_divstr(&buf[fd], verifn(buf[fd])));
			if (buf[fd])
				return (ft_free(&buf[fd]));
			return (FT_NULL);
		}
		buf[fd] = ft_join(buf[fd], tmp);
		if (verifn(buf[fd]) != -1)
			return (ft_divstr(&buf[fd], verifn(buf[fd])));
	}
	return ((char *)FT_NULL);
}

char *get_next_line(int fd)
{
	int			r;
	static char	*buf[1024];
	char		*tmp;
	
	r = 1;
	tmp = FT_NULL;
	if (buf[fd] && verifn(buf[fd]) != -1)
		return (ft_divstr(&buf[fd], verifn(buf[fd])));
	return (ft_loop(tmp, buf, r, fd));
}
