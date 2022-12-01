/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madaguen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:44:25 by madaguen          #+#    #+#             */
/*   Updated: 2022/11/30 23:01:21 by madaguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# define FT_NULL (void *)0
//# define BUFFER_SIZE 1024

int		ft_strlen(char *s1);
int		verifn(char *buf);
char	*ft_divstr(char **buf, int i);
char	*ft_join(char *s1, char *s2);
void	*ft_free(char **buf);
char	*ft_loop(char *tmp, char **buf, int r, int fd);
char	*get_next_line(int fd);

#endif