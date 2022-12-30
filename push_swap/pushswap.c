#include <push_swap.h>

int	main(int ac, char **av)
{
	t_list	*a;
	char	**tab;
	int		check;
	a = NULL;
	if (ac == 1)
	{
		tab = ft_get_stdin();
			if (!tab)
				return (error());
		check = ft_create_stack(ft_tablen(tab), tab, &a);
		free_tab(tab);
	}
	else
		check = ft_create_stack(ac - 1, &av[1], &a);
	if (!check)
		return (error());
	if (!ft_sort(&a))
		return (error());
}
