/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madaguen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 02:47:49 by madaguen          #+#    #+#             */
/*   Updated: 2022/11/22 03:26:12 by madaguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *get_next_line(int fd)
{
	int			r;
	static char	*buf[FOPEN_MAX];
	char		*tmp;
	
	r = 1;
	if (verifn(buf[fd]));
		return (substr(buf, fd, 1));
	while (r)
	{
		tmp = malloc(BUFFER_SIZE + 1);
		if (!tmp)
			return (NULL);
		r = read(fd, tmp, BUFFER_SIZE);
		if (r <= 0)
			return (free(buf));
		if (r < BUFFER_SIZE && !verifn(tmp))
		{
			ft_free(buf);
			return (tmp);
		}
		if (r < BUFFER_SIZE)
			return(ft_substr(buff, fd, 1));	
		buf[fd] = ft_strjoin(buf[fd], tmp);
		if (verifn(buf[fd]))
			return (ft_substr(buf, fd, 1));
	}
}
