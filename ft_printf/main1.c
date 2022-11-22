
int main()
{
	long int a = 1235645664224444;
	int b = a;

	printf("%ld\n%d\n",a,b);
	printf("%d", 1235645664224444);

	printf("\n\n");
  char  c = 'a';
  char s[] = "coucou";
  int j =  printf("test vrai printf = %d,%c,%u,%s,%p,%x,%X,\n", 20, c, -20, s, &c, 42, 42);
  int i = ft_printf("test mon printf = %d,%c,%u,%s,%p,%x,%X,\n", 20, c, -20, s, &c,42, 42);
  ft_printf("j = %d i = %d", a, i);
  return 0;

}
