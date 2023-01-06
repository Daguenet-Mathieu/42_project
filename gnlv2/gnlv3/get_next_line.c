/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madaguen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:47:28 by madaguen          #+#    #+#             */
/*   Updated: 2023/01/06 19:36:12 by madaguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	find_nl(char *str, int *len, int *n)
{
	int		i;

	i = 0;
	*n = -1;
	*len = 0;
	if (!str)
		return ;
	while (str[*len])
		(*len)++;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			*n = i;
			return ;
		}
		i++;
	}
}

void	lst_new_add(t_read **start, char **buf, int *i)
{
	char	*content;
	t_read	*new;
	t_read	*temp;

	new = malloc(sizeof(t_read));
	if (!new)
		return ;
//	printf("new = %p\n", new);
//	printf("buf = %p\n", *buf);
	content = *buf;
	*buf = NULL;
	new->read = content;
//	printf("content = %p\n new->read = %p \n", content, new->read);
	new->size = i[0];
	new->n = i[1];
	new->next = NULL;
	if (!*start)
	{
		*start = new;
		return ;
	}
	temp = *start;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}

void	ft_cpy_lst(t_read **start, t_read *tmp, char *line, char **buf, int *i)
{
	i[1] = 0;
	//printf("start = %p *start = %p *start->next = %p line = %p buf = %p\n", start, *start, (*start)->next, line, *buf);
	while (*start && line && (*start)->next)
	{
		i[0] = 0;
		while ((*start)->read[i[0]])
			line[i[1]++] = (*start)->read[i[0]++];
	//	printf("free start->read = %p\n", (*start)->read);
		free((*start)->read);
		tmp = (*start)->next;
		free(*start);
//		printf("free start = %p\n", *start);
		*start = tmp;
		line[i[1]] = 0;
	}
	i[0] = 0;
	i[2] = (*start)->n;
//	printf("start = %p *start = %p *start->next = %p line = %p buf = %p\n", start, *start, (*start)->next, line, *buf);
	while (*start && line && (*start)->read[i[0]])
	{
//		printf(" pas free start->read = %p\n", (*start)->read);
//		printf("free start->read = %p\n", (*start)->read);
		line[i[1]++] = ((*start)->read[i[0]++]);
		line[i[1]] = 0;
		if (*buf && (*start)->read[i[0]])
			(*buf)[(i[2]-(*start)->n)] = ((*start)->read[i[2]]);
		i[2]++;
	}
		free((*start)->read);
		free(*start);
//		printf("free start->read = %p\n", (*start)->read);
}

char	*ft_lst_join(t_read **start, char **buf)
{
	char	*line;
	t_read	*tmp;
	int		size[2];
	int		i[3];

	tmp = *start;
	size[0] = 0;
	while (tmp->next)
	{
		size[0] += tmp->size;
		tmp = tmp->next;
	}
//	if (tmp->n == -1)
//		size[0] += tmp->size;
//	else
	size[0] += (-1 * (tmp->n - tmp->size)) + 1;
//	printf("size = %d\n", size[0]);
	size[1] = tmp->size - tmp->n;
	if (tmp->n == -1)
		size[1] = 0;
	line = NULL;
	*buf = NULL;
	if (size[0] > 1)
		line = malloc(size[0] + 1);
	if (size[1] > 1)
		*buf = malloc(size[1] + 1);
//	printf("%d\n%d\n%d\n",size[0], size[1], tmp->n);
	tmp = NULL;
	return ((ft_cpy_lst(start, tmp, line, buf, i)), line);
}

char	*get_next_line(int fd)
{
	static char	*buf[1024];
	t_read		*start;
	int			i[3];

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	start = NULL;
	i[2] = -1;
	while (1)
	{
		find_nl(buf[fd], &i[0], &i[1]);
		if (buf[fd])
			lst_new_add(&start, &buf[fd], i);
		if (i[1] != -1 || i[2] == 0)
			return (ft_lst_join(&start, &buf[fd]));
		buf[fd] = malloc(BUFFER_SIZE + 1);
		if (!buf[fd])
			return (NULL);
	//	printf("buf[fd] = %p\n", buf[fd]);
		i[2] = read(fd, buf[fd], BUFFER_SIZE);
		if (!start && i[2] <= 0)
			return (free(buf[fd]), NULL);
		buf[fd][i[2]] = 0;
	}
	return (NULL);
}

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main()
{
	int fd = open("1-brouette.txt", O_RDONLY);
	int a = 1;
	char *line;
	while (a)
	{
		line = get_next_line(fd);
		printf("res = %s", line);
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
