#include "push_swap.h"

int	ft_lst_size(t_list *a)
{
	t_list	*tmp;

	tmp = a;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

void	ft_sort_tab(int	*tab, int size)
{
	int	i;
	int	tmp;

	i = 0;
	while (i + 1 < size)
	{
		if (tab[i] > tab[i + 1])
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			i = -1;
		}
		i++;
	}
}

int	*sort_index(t_list *a, int size)
{
	int		*tab;
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = a
	tab = malloc(size * sizeof(int));
	if(!tab)
		return (NULL);
	while (tmp)
	{
		tab[i] = tmp->nb;
		tmp = tmp->next;
		i++;
	}
	ft_sort_tab(tab, size);
	return (tab);
}

void	set_index(t_list **a, int *tab, int size)
{
	int		i;
	t_list	*tmp;

	tmp = *a
	while (tmp->next)
	{
		i = 0;
		while (i < size && tab[i] != tmp->nb)
			i++;
		tmp->nb = i;
	}
}

void	ft_sort(t_list **a)
{
	t_list	*b;
	int		*tab;
	int		size;

	b = NULL;
	size = ft_lst_size(*a);
	tab = sort_index(*a, size);
	if (!check_double(tab))
		return (0)
	set_index(a, tab, size);
	push_swap(a, &b);
	free (tab);
}
