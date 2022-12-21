void	get_lst(t_list **a)
{

}

void	ft_create_stack(int ac, char **av, t_list **a)
{
	int 	i;
	t_list	*new;

	i = 1;
	{
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
	}
}

int	main(int ac, char **av)
{
	t_list	*a;

	a = NULL;
	if (ac == 1)
	{
		get_lst(&a);
		if (!*a)
			return (0);
	}
	else
		ft_create_stack(ac, av, &a)
	ft_sort(&a);
	ft_swap(&a);
}
