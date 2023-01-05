#include <push_swap.h>

int	*join_av(int ac, char **a, int *size)
{
	int	i;
	int	*tab

	i = 0;
	while (i < ac)
	{
		if(!check_arg(av[i]))
		{
			free
			return (NULL);
		}
		join();
	}
	return (tab);
}

int ft_create_stack(int ac, char **av, t_list **a)
{
    int     i;
    t_list  *new;
	int		*tab;
	int		*size;

    i = 0;

	tab = join_av(ac, av, &size);
    while (i < ac)
    {
        if (!ft_atoi(av[i]))
            return (0);
        i++;
    }
    i = 0;
    while (i < ac)
    {
        new = lst_new(ft_atoi(av[i]));
        if(!new)
        {
            ft_lst_clear(&a);
            return (0);
        }
        lst_add_back(&a, new);
    }
    return (1);
}
