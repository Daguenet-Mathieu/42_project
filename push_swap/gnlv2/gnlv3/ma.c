int main()
{
	char **tab = split("1 2 3" " ");
	char **tab1 = split("4 5 6" " ");
	char **tab2 = split("7 8 9" " ");

	int	i = 0;
	t_list *lst = NULL;
	t_list	*new

	while (tab[i])
	{
		new = ft_lstnew(tab[i]);
		ft_lst_add_back(new);
		i++;
	}
	i = 0;
	while (tab1[i])
	{
		new = ft_lstnew(tab1[i]);
		ft_lst_add_back(new);
		i++;
	}
	i = 0;
	while (tab2[i])
	{
		new = ft_lstnew(tab[i]);
		ft_lst_add_front(new);
		i++;
	}
	printf("%d\n", ft_lst_size(lst));
	//t_list tmp = lst;
	while (lst)
	{
		printf("%s\n", lst->content);
		lst = lst->next;
	}
	ft_lst_clear(&lst);
}
