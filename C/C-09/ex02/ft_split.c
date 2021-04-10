/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 21:33:44 by tdayde            #+#    #+#             */
/*   Updated: 2020/09/03 18:54:16 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_on_charset(char c, char *charset)
{
	int i;

	i = -1;
	while (charset[++i])
		if (charset[i] == c)
			return (1);
	return (0);
}

int		nbr_of_words(char *str, char *charset)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (is_on_charset(str[i], charset) && str[i])
			i++;
		if (!is_on_charset(str[i], charset) && str[i])
			count++;
		while (!is_on_charset(str[i], charset) && str[i])
			i++;
	}
	return (count);
}

char	**malloc_str(char *str, char *charset)
{
	int		i;
	int		k;
	int		len_word;
	char	**tab;

	i = 0;
	k = 0;
	tab = malloc(sizeof(*tab) * ((nbr_of_words(str, charset) + 1)));
	while (str[i])
	{
		len_word = 0;
		while (is_on_charset(str[i], charset) && str[i])
			i++;
		while (!is_on_charset(str[i], charset) && str[i])
		{
			len_word++;
			i++;
		}
		if ((is_on_charset(str[i], charset) || !str[i]) && len_word > 0)
			tab[k++] = malloc(sizeof(**tab) * (len_word + 1));
	}
	tab[k] = 0;
	return (tab);
}

char	**fill_tab(char *str, char *charset, char **tab)
{
	int i;
	int j;
	int k;

	i = 0;
	k = 0;
	while (str[i])
	{
		j = 0;
		while (is_on_charset(str[i], charset) && str[i])
			i++;
		while (!is_on_charset(str[i], charset) && str[i])
			tab[k][j++] = str[i++];
		if (is_on_charset(str[i], charset))
		{
			tab[k][j] = '\0';
			k++;
		}
		else if (str[i] != '\0')
			tab[k][j] = '\0';
	}
	return (tab);
}

char	**ft_split(char *str, char *charset)
{
	char	**tab;
	int		i;

	i = -1;
	if (charset[0] == '\0')
	{
		while (str[++i])
			i++;
		tab = malloc(sizeof(*tab) * 2);
		tab[0] = malloc(sizeof(**tab) * (i + 1));
		tab[1] = malloc(sizeof(**tab) * 1);
		i = -1;
		while (str[++i])
			tab[0][i] = str[i];
		tab[0][i] = '\0';
		tab[1] = 0;
		return (tab);
	}
	else
	{
		tab = malloc_str(str, charset);
		tab = fill_tab(str, charset, tab);
	}
	return (tab);
}
