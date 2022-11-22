#include <stdio.h>
int ft_printf(char *fortmat, ...);

int	main()
{
	//TEST %c
	char  c;
	c = 's';
	printf("%d \n", ft_printf("hello le %c\n", c) == printf("hello le %c\n", c));
	
	//TEST %s
	char *str;
	str = "gg alex pour ce testeur du turfu";
	printf("%d \n", ft_printf("%s\n", str) == printf("%s\n", str));
	ft_printf("%s\n", NULL);
	//TEST %%
	printf("%d \n", ft_printf("%%\n") == printf("%%\n"));
	ft_printf("%\n");
	ft_printf("%\n");

	//TEST %p

	printf("%d \n", ft_printf("%p\n", NULL) == printf("%p\n", NULL));
	printf("%d \n", ft_printf("%p\n", "fewfwefewfwef") == printf("%p\n", "dwefwefwefe"));
	//TEST %i et %d
	int o;
	o = -2147483648;

	printf("%d \n", ft_printf("%i\n", o) == printf("%i\n", o));
	printf("%d \n", ft_printf("%d\n", o) == printf("%d\n", o));

	//TEST %u
	unsigned int ui;
	ui = -1;
	printf("%d \n", ft_printf("%u\n", ui) == printf("%u\n", ui));

	//TEST %x
	unsigned int x;
	x = 5645;
	printf("%d \n", ft_printf("%x\n", x) == printf("%x\n", x));

	unsigned int X;
	X = 5645;
	printf("%d \n", ft_printf("%X\n",X) == printf("%X\n",X));

	ft_printf("%k\n");
	printf("%k\n");
}
