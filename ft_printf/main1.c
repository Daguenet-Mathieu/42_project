#include <stdio.h>
#include <stddef.h>
#include "libftprintf.h"

int main()
{
	long int a = 1235645664224444;
	int b = a;

	printf("%ld\n%d\n",a,b);
	printf("%ld", 1235645664224444);

	printf("\n\n");
  char  c = 'a';
  char s[] = "coucou";
  char *str = NULL; 
  char str2[] = "";
  int j =  printf("test vrai printf = %x,%X,\n", -42, 42);
  int i = ft_printf("test mon printf = %x,%X,\n",-42, 42);
  ft_printf("j = %d i = %d\n", a, i);
  printf("test 1 %s\n", str);
  ft_printf("test 1 %s\n", str);
  printf("test 2 %s\n", str2);
  ft_printf("test 3 %s\n", str2);
  ft_printf("test 4 %p\n", str);
  printf("test 4 %p\n", str);
  ft_printf("%i %i", 2147483647, (int)-2147483648);
  ft_printf("%d", (int)-2147483648);
  ft_printf("\n%p\n", &c);
  printf("%p\n", &c);
  return 0;

}
