/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madaguen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:34:38 by madaguen          #+#    #+#             */
/*   Updated: 2022/12/06 22:04:14 by madaguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <ulimit.h>
#include "get_next_line.h"

//void	test(char  **tab)
//{
//	printf("%p\n", tab);
//	free(tab[0]);
//	free(tab);
//}

int main(/*int ac, char **av, char **e*/)
{
//char *tab[2];

//	printf("%p,%p\n", tab, *tab);
	  int t;
	  t = 0;
//	char	**tab = malloc(1);
//	*tab = malloc(1);
//	tab[0][0] = 122;
//	printf("%c\n", **tab);
//	printf("%p\n", tab);
//	printf("%p\n", *tab);
//	test(tab);
//	printf("%p\n", tab);
//	free(tab);
//	printf("%c\n", **tab);
//	char	*test = FT_NULL;
//	printf("%p\n%s\n", test, test);
/*	for(;;)
  	{
    	t = open("test", O_RDONLY);
		if (t < 0)
		{
			printf("test = %d\n",errno);
			perror("open");
      		exit(1);
		}
 		printf("%d: ok\n", t);
		printf("%d\n%d\n",FOPEN_MAX, errno);
	}
	for (int i = 0; i < 140; i++)
	{
		errno = i;
		printf("erno = %d\n", errno);
      	perror("test perror");

	}
	while (*e)
		printf("env = %s\n", *e++);*/
//	  printf("%ld", __UL_GETOPENMAX);
    	t = open("bible.txt", O_RDONLY);
		 char	*r;
		 int o = 1;
		
//		 r = get_next_line(t);
//		 printf(" res : %s", r);
		 while (o)
		 {
		 	r = get_next_line(t);
		 	if (!r)
		 		o = 0;
		 	printf(" res : %s", r);
			if (r)
			{
				if(r[0] == 0)
					printf("coucou");
			}
			free(r);
		 }
	//printf("%d", t);
	char *line;

	while ((line = get_next_line(t)))
	{
		printf("%s", line);
		free(line);	
	}
	free(line);
 	return (0);
}
