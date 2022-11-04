#include "libft.h"
#include "string.h"
#include "stdio.h"
#include "ctype.h"
#include <bsd/string.h>

int	main(void)
{
	printf("test ft_isalpha\n");

	int	test = 1;
	for (int i = -256; i < 257; i++)
	{
		if ((!ft_isalpha(i) && isalpha(i)) || (!isalpha(i) && ft_isalpha(i)))
		{
			printf ("erreur pour i = %d ma fonction = %d et la vrai = %d\n", i, ft_isalpha(i), isalpha(i));
			test = 0;
		}
	}
	if (test)
		printf ("ok");
	
	printf("\ntest ft_isdigit\n");
	
	test = 1;
	for (int i = -256; i < 257; i++)
	{
		if ((!ft_isdigit(i) && isdigit(i)) || (!isdigit(i) && ft_isdigit(i)))
		{
			printf ("erreur pour i = %d ma fonction = %d et la vrai = %d\n", i, ft_isdigit(i), isdigit(i));
			test = 0;
		}
	}
	if (test)
		printf ("ok");
	
	printf("\ntest ft_isalnum\n");
	test = 1;
	for (int i = -256; i < 257; i++)
	{
		if ((!ft_isalnum(i) && isalnum(i)) || (!isalnum(i) && ft_isalnum(i)))
		{
			printf ("erreur pour i = %d ma fonction = %d et la vrai = %d\n", i, ft_isalnum(i), isalnum(i));
			test = 0;
		}
	}
	if (test)
		printf ("ok");
	
	printf("\ntest ft_isascii\n");
	
	test = 1;
	for (int i = -256; i < 257; i++)
	{
		if ((!ft_isascii(i) && isascii(i)) || (!isascii(i) && ft_isascii(i)))
		{
			printf ("erreur pour i = %d ma fonction = %d et la vrai = %d\n", i, ft_isascii(i), isascii(i));
			test = 0;
		}
	}
	if (test)
		printf ("ok");
	
	printf("\ntest ft_isprint\n");
	
	test = 1;
	for (int i = -256; i < 257; i++)
	{
		if ((!ft_isprint(i) && isprint(i)) || (!isprint(i) && ft_isprint(i)))
		{
			printf ("erreur pour i = %d ma fonction = %d et la vrai = %d\n", i, ft_isprint(i), isprint(i));
			test = 0;
		}
	}
	if (test)
		printf ("ok");

	printf("\ntest ft_strlen\n");

	if ((strlen("") == ft_strlen("")) && (strlen("coucou") == ft_strlen("coucou")) && (strlen("un dernier test") == ft_strlen("un dernier test")))
		printf("ok");
	else
		printf("erreur");
	

	printf("\ntest ft_memset\n");
	char	memtest[10];
	char	memtest2[10];
	test = 1;
	memset(memtest, 49, 10);
	ft_memset(memtest2, 49, 10);
	for (int i = 0; i < 10; i++)
	{
		if (memtest[i] != memtest2[i])
		{
			printf("erreur");
			test = 0;
		}
	}
	if (test)
		printf("ok");
	
	printf("\ntest ft_bzero\n");
	char	bzerotest[10];
	char	ftbzerotest[10];
	bzero(bzerotest, 10);
	ft_bzero(ftbzerotest, 10);
	for (int i = 0; i < 10; i++)
	{
		if (bzerotest[i] != ftbzerotest[i])
		{
			printf("erreur");
			test = 0;
		}
	}
	if (test)
		printf("ok");

	printf("\ntest ft_memcpy\n");
	char	memsrc[16] = "je fais un test";
	char	testmemcpy[16];
	char	testftmemcpy[16];
	memcpy(testmemcpy, memsrc, 16);
	ft_memcpy(testftmemcpy, memsrc, 16);
	for (int i = 0; i < 16; i++)
	{
		if (testftmemcpy[i] != testmemcpy[i])
		{
			printf("erreur");
			test = 0;
		}
	}
	if (test)
		printf("ok");


	printf("\ntest ft_memmove\n");
	char	mmtestsrc[50] = "je fais un test";
	char	ftmmtestsrc[50] = "je fais un test";
	memmove(mmtestsrc + 5, mmtestsrc, 16);
	ft_memmove(ftmmtestsrc + 5, ftmmtestsrc, 16);
	for (int i = 0; i < 22; i++)
	{
		if (mmtestsrc[i] != ftmmtestsrc[i])
		{
			printf("erreur");
			test = 0;
		}
	}
	if (test)
		printf("ok");


	printf("\ntest ft_strlcpy\n");
	char srcstrlcpy[] = "je fais un test";
	char deststrlcpy[16];
	char destftstrlcpy[16];
	int a = strlcpy(deststrlcpy, srcstrlcpy, 16);
	int b = ft_strlcpy(destftstrlcpy, srcstrlcpy, 16);
	printf ("%d%s",a, deststrlcpy);
	printf ("\n%d%s",b, destftstrlcpy);

	printf("\ntest ft_strlcat\n");
	char srcstrlcat[] = " encore!!";
	char deststrlcat[25] = "je fais un test";
	char destftstrlcat[25] = "je fais un test";
	a = strlcat(deststrlcat, srcstrlcat, 25);
	b = ft_strlcat(destftstrlcat, srcstrlcat, 25);
	printf ("%d%s",a, deststrlcat);
	printf ("\n%d%s",b, destftstrlcat);

	printf("\ntest ft_toupper\n");
	printf("\ntest ft_tolower\n");
	printf("\ntest ft_strchr\n");
	printf("\ntest ft_strrchr\n");
	printf("\ntest ft_strncmp\n");
	printf("\ntest ft_memchr\n");
	printf("\ntest ft_memcmp\n");
	printf("\ntest ft_strnstr\n");
	printf("\ntest ft_atoi\n");
	printf("\ntest ft_calloc\n");
	printf("\ntest ft_strdup\n");
	printf("\ntest ft_substr\n");
	printf("\ntest ft_strjoin\n");
	printf("\ntest ft_strtrim\n");
	printf("\ntest ft_split\n");
	printf("\ntest ft_itoa\n");
}
