#include <push_swap.h>

int ft_checktab(int size, char **tab)
{
    int i;

    i = 0;
    if (!tab)
        return (0);
    while (tab[i])
    {
        if (!ft_isvalid(tab[i]))
            return (0);
        i++;
    }
    return (1);
}

int ft_isvalid(char *s)
{
    int i;

    i = 0;
    while (s[i] && ft_space(s[i]))
        i++;
    if (s[i] == '-' || s[i] == '+')
        i++;
    while (ft_isdigit(s[i]))
        i++;
    if (s[i] == 0)
        return (1);
    return (0); 
}

char    *ft_join(char *s, char c)
{
    char    *s1;
    int     i;

    i = 0;
    if (!s)
    {
        s1 = malloc(1);
        if (!s1)
            return (NULL);
        s1[0] = c;
    }
    else
    {
        s1 = malloc(ft_strlen(s) + 2);
        if (!s1)
            return (NULL);
        while (s[i])
        {
            s1[i] = s[i];
            i++;
        }
        s1[i] = c;
        s1[i + 1] = 0;
    }
    return (s1);
}


char    **ft_get_stdin(char *s)
{
    char    *s;
    char    **tab;
    int     r;
    char    c;

    s = NULL;
    r = 1;
    while (r > 0)
    {
        r = read(0, c, 1);
        if (r)
            s = ft_join(s, c);
    }
    if (!ft_check(s))
        return (NULL);
    tab = ft_split(s);
    return (tab);
}

int ft_create_stack(int ac, char **av, t_list **a)
{
    int     i;
    t_list  *new;

    i = 0;
    if (!ft_checktab(av))
        return (0);
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

