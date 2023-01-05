/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madaguen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 13:25:47 by madaguen          #+#    #+#             */
/*   Updated: 2022/12/31 15:46:59 by madaguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1 
# endif
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>

typedef struct s_read
{
    char                *read;
    int                 size;
    struct s_read       *next;
}                       t_read;

t_read	*lst_new_read(char *content, int size ); 
void	lst_add_back(t_read **lst, t_read *new); 
char	*get_next_line(int fd);

#endif
