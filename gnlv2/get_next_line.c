/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madaguen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:13:40 by madaguen          #+#    #+#             */
/*   Updated: 2022/12/17 00:10:39 by madaguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_read	*lst_new_read(char *content, int size)
{
	t_read	*new;

	new = malloc(sizeof(t_read));
	new->next = NULL;
	new->size = size;
	new->read = content;

	return (new);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return(i);
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

void	ft_strcpy(char *s1, char *s2, int *i)
{
	int	c;

	c = 0;
	while(s2[c])
	{
		s1[c] = s2[c];
		(*i)++;
		c++;
	}
}

void	lst_add_back(t_read **lst, t_read *new)
{
	t_read	*tmp;

	tmp = *lst;
	if (!*lst)
		*lst = new;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

char *ft_substr(char *s, int len)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(len + 1);
	while (i < len)
	{
		str[i] = s[i];
			i++;
	}
	str[i] = 0;
	return (str);
}

char	*ft_lstjoin(t_read **start, int r)
{
	t_read	*tmp;
	int		size;
	char	*str;
	int		i;

	i = 0;
	tmp = *start;
	size = 0;
	while (tmp)
	{
		size += tmp->size;
		tmp = tmp->next;
	}
	str = malloc(size + 1);
	str[size] = 0;
	while (*start)
	{
		ft_strcpy(str + i, (*start)->read, &i);
		tmp = (*start)->next;
		free((*start)->read);
		free(*start);
		*start = tmp;
	}
	return (str);
}

char	*handle_read(char **buf, t_read **start, int r)
{
	char	*tmp;
	char	*line;
	int		n;
	int		i;

	i = 0;
	tmp = ft_lstjoin(start, r);
	if(!tmp)
		return(NULL);
	if (!*buf)
		*buf = tmp;
	else
	{
		line = malloc(ft_strlen(*buf) + ft_strlen(tmp) + 1);
		ft_strcpy(line + i, *buf, &i);
		ft_strcpy(line + i, tmp, &i);
		free(*buf);
		*buf = line;
	}
	n = find_n(*buf);
	line = ft_substr(*buf, n + 1);
	tmp = ft_substr(&(*buf)[n + 1], ft_strlen(&(*buf)[n + 1]));
	free(*buf);
	*buf = tmp;
	return (line);
}

char	*ft_read(char *tmp, char **buf, int fd)
{
	t_read		*tmpread;
	t_read		*start;
	int			r;
	
	start = NULL;
	while (1)
	{
		tmp = malloc(BUFFER_SIZE + 1);
		if (!tmp)
			return (NULL);
		r = read(fd, tmp, BUFFER_SIZE);
//		printf("r = %d\n", r);
		tmp[r] = 0;
		tmpread = lst_new_read(tmp, r);
		lst_add_back(&start, tmpread);
		if (find_n(tmpread->read) != -1)
			return(handle_read(buf, &start, r));
		if (r <= 0 /*|| (r < BUFFER_SIZE)*/)
			return (NULL);
			//return(handle_read(buf, &start, r));
	}
	return (NULL);
}

char	*get_next_line(int	fd)
{
	static char	*buf[1024];
	char		*tmp;
	char		*line;
	int			n;
	static int	i;
	
	//printf("i = %d,buf = %s\n", i, buf[fd]);
	i++;
	if (buf[fd] && find_n(buf[fd]) != -1)
	{
		n = find_n(buf[fd]);
		line = ft_substr(buf[fd], n + 1);
		tmp = ft_substr(&buf[fd][n + 1], ft_strlen(&buf[fd][n + 1]));
		free(buf[fd]);
		buf[fd] = tmp;
		return (line);
	}
	return (ft_read(tmp, &buf[fd], fd));
}

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main()
{
	int fd = open("bible.txt", O_RDONLY);
	int a = 1;
	char *line;
	while (a)
	{
		line = get_next_line(fd);
		printf("%s", line);
		if(!line)
			a = 0;
		//a++;
		free(line);
	}
}
