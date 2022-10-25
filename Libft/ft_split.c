#include "libft.h"

static int	is_sep(char c, char a)
{
	if (c == a)
		return (1);
	return (0);
}

static char	get_nb_word(char *s, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	if (!is_sep(c, s[i]))
		word++;
	i++;
	while (s[i])
	{
		if (is_sep(c, s[i - 1]) && !is_sep(i))
			word++;
		i++;
	}
	return (word);
}

static char	*get_word(char *s, char c,int *i)
{
	char	*new_word;
	int	c;
	int	j;

	c = 0;
	j = 0;
	if (!s)
		return (NULL);
	while (s[i] && is_sep(c, s[*i]))
		(*i)++;
	while (s[*i + j] && !is_sep(c, s[*i + j]))
		j++;
	while (c < j)
	{
		new_word[c] = s[*i];
		c++;
		(*i)++;
	}
	new_word[c] = '\0';
	return (new_word);
}

char	**ft_split(char const *s, char c)
{
	int	i;
	int	j;
	char	**tab;
	int	nb_word;

	i = 0;
	c = 0;
	if (!*s)
		return (NULL);
	nb_word = get_nb_word(s, c);
	split = malloc(sizeof(char*) * (nb_word + 1));
	if (!split)
		return (NULL);
	while (j < nb_word)
	{
		split[j] = get_word(s, c, &i);
		j++;
	}
	tab[j] = NULL;
	return (tab);
}
