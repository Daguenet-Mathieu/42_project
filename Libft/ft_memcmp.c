#include "libft.h"

int	memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	unsigned char	*ps1;
	unsigned char	*ps2;

	ps1 = (unsigned char *) s1;
	ps2 = (unsigned char *) s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n && ps1[i] == ps2[i])
		i++;
	return (ps1[i] - ps2[i]);
}
