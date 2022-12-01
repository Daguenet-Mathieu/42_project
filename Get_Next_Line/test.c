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

void	test(char  **tab)
{
	printf("%p\n", tab);
//	free(tab[0]);
//	free(tab);
}
int main(int ac, char **av, char **e)
{
//char *tab[2];

//	printf("%p,%p\n", tab, *tab);
	  int t;
//	  t = 0;
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

  		int i = 0; 
    	t = open("test", O_RDONLY);
		char	*r;
		while (i < 3)
		{
			r = get_next_line(t);
			printf(" test : %s", r);
			free (r);
			i++;
		}
}
