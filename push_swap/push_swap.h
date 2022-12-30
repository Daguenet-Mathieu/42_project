/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madaguen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:26:38 by madaguen          #+#    #+#             */
/*   Updated: 2022/12/16 13:30:34 by madaguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H
 #include <unistd.h>
 #include <stdlib.h>
 #include <stddef.h>

typedef struct s_list
{
	int				nb;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

typedef	struct s_step
{
	int		step;
	s_step	*next;
}			t_step;

t_list	*lst_new(int a);
void	swap(t_list **lsta, t_list **lstb);
void	push(t_list **lsta, t_list **t_lstb);
void	add_back(t_list **lst, t_list *new);
int		lst_size(t_list **lst);
void	radix_sort(t_list **lst);
void	sort(t_list **lst);
char	*get_next_line(int fd);
int		ft_atoi(char *nbr, int *nb);
void	ft_lst_clear(t_list **a, t_step **step);

#endif
