/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madaguen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:44:25 by madaguen          #+#    #+#             */
/*   Updated: 2022/12/01 19:31:31 by madaguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# ifndef FT_NULL
#  define FT_NULL (void *)0
# endif
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

int		ft_strlen(char *s1);
int		verifn(char *buf);
char	*ft_divstr(char **buf, int i);
char	*ft_join(char *s1, char *s2);
void	*ft_free(char **buf);
char	*ft_loop(char *tmp, char **buf, int r, int fd);
char	*get_next_line(int fd);

#endif
