/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madaguen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:27:29 by madaguen          #+#    #+#             */
/*   Updated: 2022/11/16 22:03:20 by madaguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	get_nb(long long int *nb, int size, char *s)
{
	int	i;

	i = 0;	
	while (*nb > 0)
	{
		s[size - 1 - i] = (*nb % 10) + 48;
		*nb = *nb / 10;
		i++;
	}
}

static void	get_size(long long int nb, int *size)
{
	if (nb == 0)
		*size = 1;
	while (nb > 0)
	{
		(*size)++;
		nb = nb / 10;
	}
}

char	*ft_itoa(int n)
{
	char			*s;
	int				size;
	long long int	nb;
	int				neg;

	nb = n;
	neg = 0;
	size = 0;
	if (nb < 0)
	{
		size ++;
		neg = 1;
		nb = nb * -1;
	}
	get_size(nb, &size);
	s = malloc(sizeof(char) * (size + 1));
	if (!s)
		return (NULL);
	if (nb == 0)
		s[0] = '0';
	if(neg)
		s[0] = '-';
	get_nb(&nb, size, s);
	s[size] = '\0';
	return (s);
}
