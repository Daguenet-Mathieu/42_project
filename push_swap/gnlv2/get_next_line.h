/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madaguen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 13:25:47 by madaguen          #+#    #+#             */
/*   Updated: 2023/01/02 19:57:00 by madaguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1 
# endif
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>

typedef struct s_read
{
	char			*read;
	int				size;
	int				n;
	struct s_read	*next;
}					t_read;

void	lst_add_new(t_read **lst, t_read *new);
char	*get_next_line(int fd);

#endif
