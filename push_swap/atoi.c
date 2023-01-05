int ft_isdigit(char c) 
{ 
    return ((c >= '0' && c <= '9')); 
} 
 
int ft_space(char c) 
{ 
    int i; 
 
    i = 0; 
    if ( c == 32 || (c <= 13 && c >= 9)) 
        i = 1; 
    return (i); 
}

void    ft_skip(char *s, int *i)
{  
    while (ft_space(s[*i])) 
        (*i)++; 
    if (s[*i] == '+' || s[*i] == '-') 
    { 
        if (s[*i] == '-') 
            sign = 1; 
        (*i)++; 
    } 
}

int    ft_atoi(char *nbr, int *nb)
{
    long    n;
    int     sign;
    int     v;
    int     i;

    sign = 0;
    n = 0;
    v = 1;
	ft_skip(nbr, &i);
    while (ft_isdigit(nbr[i]) && n <= INT_MAX + 1)
    {
        n = n * 10 + nbr[i] - '0';
        i++;
    }
    if (sign)
        n = n * -1;
    if (n > INT_MAX || n < INT_MIN)
        v = 0;
    else
        *nb = n;
    return (v);
}
