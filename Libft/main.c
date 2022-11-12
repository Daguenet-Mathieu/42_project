#include "libft.h"
#include "string.h"
#include "stdio.h"
#include "ctype.h"
#include <limits.h>
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
	printf("la mienne: %s\nlavrai:%s\n",ftmmtestsrc,mmtestsrc);


	printf("\ntest ft_strlcpy\n");
	char srcstrlcpy[] = "je fais un test";
	char deststrlcpy[111];
	char destftstrlcpy[111];
	int a = strlcpy(deststrlcpy, srcstrlcpy, 111);
	int b = ft_strlcpy(destftstrlcpy, srcstrlcpy, 111);
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

	test = 1;
	for (int i = 0; i < 256; i++)
	{
		if (ft_toupper(i) != toupper(i))
		{
			printf("i = %d ma fonction = %d la vrai fonction = %d\n", i, ft_toupper(i),toupper(i));
			test = 0;
		}
	}
	if (test)
		printf("ok");

	printf("\ntest ft_tolower\n");

	test = 1;
	for (int i = 0; i < 256; i++)
	{
		if (ft_tolower(i) != tolower(i))
		{
			printf("i = %d ma fonction = %d la vrai fonction = %d\n", i, ft_tolower(i),tolower(i));
			test = 0;
		}
	}
	if (test)
		printf("ok");

	printf("\ntest ft_strchr\n");

	char *testftstrchr = ft_strchr("blabla", 97);
	char *teststrchr = strchr("blabla", 97);
	char *testftstrchr2 = ft_strchr("blqblq", 0);
	char *teststrchr2 = strchr("blqblq", 0);
	char *testftstrchr3 = ft_strchr("", 0);
	char *teststrchr3 = strchr("", 0);
	
	printf("1:la mienne:%s  la vrai:%s\n2:la mienne:%s  la vrai:%s\n3:la miennne:%s la vrai:%s", testftstrchr,teststrchr,testftstrchr2,teststrchr2,testftstrchr3,teststrchr3);

	printf("\ntest ft_strrchr\n");

	char *testftstrrchr = ft_strrchr("blablahhhh", 97);
	char *teststrrchr = strrchr("blablahhh", 97);
	char *testftstrrchr2 = ft_strrchr("blqblqhhh", 0);
	char *teststrrchr2 = strrchr("blqblqhhhh", 0);
	char *testftstrrchr3 = ft_strrchr("", 0);
	char *teststrrchr3 = strrchr("", 0);
	
	printf("1:la mienne:%s  la vrai:%s\n2:la mienne:%s  la vrai:%s\n3:la miennne:%s la vrai:%s", testftstrrchr,teststrrchr,testftstrrchr2,teststrrchr2,testftstrrchr3,teststrrchr3);


	printf("\ntest ft_strncmp\n");
	
	char big[] = "salut, ca va?";
	char to_find[] = "oui";
	char to_find1[] = "t,";
	test = 1;
	int resftstrncmp = ft_strncmp(big, to_find, 0);
	int resstrncmp = strncmp(big, to_find, 0);
	int resftstrncmp1 = ft_strncmp(big, to_find, ft_strlen(big));
	int resstrncmp1 = strncmp(big, to_find, ft_strlen(big));
	int resftstrncmp2 = ft_strncmp(big, to_find1, 0);
	int resstrncmp2 = strncmp(big, to_find1, 0);
	int resftstrncmp3 = ft_strncmp(big, to_find1, 5);
	int resstrncmp3 = strncmp(big, to_find1, 5);
	int resftstrncmp4 = ft_strncmp(big, to_find1, 6);
	int resstrncmp4 = strncmp(big, to_find1, 6);

	if (resftstrncmp != resstrncmp)
	{
		printf("echec 1 er test valeur de retour ft = %d la vrqi = %d\n", resftstrncmp, resstrncmp);
		test = 0;
	}

	if (resftstrncmp1 != resstrncmp1)
	{
		printf("echec 2nd test valeur de retour ft = %d la vrqi = %d\n", resftstrncmp1, resstrncmp1);
		test = 0;
	}

	if (resftstrncmp2 != resstrncmp2)
	{
		printf("echec 3em test valeur de retour ft = %d la vrqi = %d\n", resftstrncmp2, resstrncmp2);
		test = 0;
	}

	if (resftstrncmp3 != resstrncmp3)
	{
		printf("echec 4e test valeur de retour ft = %d la vrqi = %d\n", resftstrncmp3, resstrncmp3);
		test = 0;
	}

	if (resftstrncmp4 != resstrncmp4)
	{
		printf("echec 5e test valeur de retour ft = %d la vrqi = %d\n", resftstrncmp4, resstrncmp4);
		test = 0;
	}

	if (test)
		printf("ok");
	printf("\ntest ft_memchr\n");
	printf("\ntest ft_memcmp\n");
	printf("\ntest ft_strnstr\n");
	
	char teststrnstr[] = "coucocou";
	char find[] = "coc";
	int o = 4;

	char *resstrnstr = strnstr(teststrnstr, find, o);
	char *resftstrnstr = ft_strnstr(teststrnstr, find, o);

	printf("ma fonction = %s\nla vrai = %s",resftstrnstr,resstrnstr);

	printf("\ntest ft_atoi && ft_itoa\n");
	char *itoatest = ft_itoa(INT_MIN);
	printf("int min = %d\n", ft_atoi(itoatest));
	itoatest = ft_itoa(INT_MAX);
	printf("int max = %d\n", ft_atoi(itoatest));
	itoatest = ft_itoa(0);
	printf("int 0 = %d\n", ft_atoi(itoatest));

	printf("\ntest ft_calloc\n");
	printf("\ntest ft_strdup\n");
	printf("\ntest ft_substr\n");

	char *subtest = '\0';
	char subtest1[] = "salut, ca va?";
	char *subtest2 = NULL;

	printf("test1 = %s\ntest2 = %s\ntest3 = %s\ntest4 = %s\ntest5 = %s\ntest6 = %s\n",ft_substr(subtest,5,0),ft_substr(subtest,0,2),ft_substr(subtest1,0,0),ft_substr(subtest1,2,15),ft_substr(subtest1,9,2),ft_substr(subtest2,3,2));


	printf("\ntest ft_strjoin\n");
	printf("\ntest ft_strtrim\n");
	printf("\ntest ft_split\n");
	printf("\ntest liste chainee");
}
