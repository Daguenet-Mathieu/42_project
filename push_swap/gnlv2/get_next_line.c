/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madaguen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:13:40 by madaguen          #+#    #+#             */
/*   Updated: 2023/01/04 20:28:56 by madaguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	lst_new_add(char *content, int size, t_read **lst)
{
	t_read	*new;
	t_read	*tmp;

	new = malloc(sizeof(t_read));
	if (!new)
		return ;
	new->next = NULL;
	new->size = size;
	new->read = content;
	tmp = *lst;
	if (*lst)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		*lst = new;
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int	find_n(char *str)
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

char	*ft_substr(char **s, int len, int index)
{
	char	*str;
	int		i;

	i = 0;
	if (len == 0)
	{
		free(*s);
		*s = NULL;
		return (NULL);
	}
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = (*s)[index + i];
			i++;
	}
	str[i] = 0;
	return (str);
}

void	ft_strcpy(char *dest, char *src)
{
	int	c;
	int	i;

	i = 0;
	c = 0;
	while (dest[i])
		i++;
	while (src[c])
	{
		dest[i] = src[c];
		c++;
		i++;
	}
	dest[i] = 0;
}

char	*ft_lstjoin(int *size, t_read **start)
{
	t_read	*tmp;
	char	*str;

	tmp = *start;
	*size = 0;
	while (tmp)
	{
		*size += tmp->size;
		tmp = tmp->next;
	}
	str = malloc(*size + 1);
	if (!str)
		return (NULL);
	str[0] = 0;
	while (*start)
	{
		ft_strcpy(str, (*start)->read);
		tmp = (*start)->next;
		free((*start)->read);
		free(*start);
		*start = tmp;
	}
	return (str);
}

char	*handle_read(char **buf, t_read **start)
{
	char	*tmp;
	char	*line;
	int		n;
	int		size;

	tmp = ft_lstjoin(&size, start);
	if (!tmp)
		return (NULL);
	n = find_n(tmp);
	if (n == -1)
		return (tmp);
	line = ft_substr(&tmp, n + 1, 0);
	if (!line)
		return (NULL);
	*buf = ft_substr(&tmp, size - n, n + 1);
	if (tmp)
		free(tmp);
	if (*buf && (*buf)[0] == 0)
	{
		free(*buf);
		*buf = NULL;
	}
	return (line);
}

char	*ft_read(char *tmp, char **buf, int fd, t_read **start)
{
	int			r;

	while (1)
	{
		tmp = malloc(BUFFER_SIZE + 1);
		if (!tmp)
			return (NULL);
		tmp[0] = 0;
		r = read(fd, tmp, BUFFER_SIZE);
		if (r <= 0 && !*start)
		{
			free(tmp);
			return (NULL);
		}
		tmp[r] = 0;
		if (r == 0)
			free(tmp);
		else
			lst_new_add(tmp, r, start);
		if (r <= 0 || (r < BUFFER_SIZE) || find_n(tmp) != -1)
			return (handle_read(buf, start));
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	t_read		*start;
	static char	*buf[1024];
	char		*tmp;
	char		*line;
	int			n;

	tmp = NULL;
	start = NULL;
	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	if (buf[fd] && find_n(buf[fd]) != -1)
	{
		n = find_n(buf[fd]);
		line = ft_substr(&buf[fd], n + 1, 0);
		tmp = ft_substr(&buf[fd], ft_strlen(&buf[fd][n + 1]), ft_strlen(line));
		free(buf[fd]);
		buf[fd] = tmp;
		return (line);
	}
	if (buf[fd])
	{
		lst_new_add(buf[fd], ft_strlen(buf[fd]), &start);
		buf[fd] = NULL;
	}
	return (ft_read(tmp, &buf[fd], fd, &start));
}
/*
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main()
{
	int fd = open("big_line_with_nl", O_RDONLY);
	int a = 1;
	char *line;
	while (a)
	{
		line = get_next_line(fd);
		//printf("res = %s", line);
		if(!line)
			a = 0;
		free(line);
	}
	// line = get_next_line(fd);
	// printf("%s", line);
	//line = get_next_line(fd);
	//printf("%s", line);
	//free(line);
	
}
*/
