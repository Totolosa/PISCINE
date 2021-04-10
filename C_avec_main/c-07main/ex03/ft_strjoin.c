/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 21:35:41 by tdayde            #+#    #+#             */
/*   Updated: 2020/08/26 12:34:10 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		len(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		len_total(int size, char **strs, char *sep)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (i < size)
	{
		count += len(strs[i]);
		if (i < size - 1)
			count += len(sep);
		i++;
	}
	return (count + 1);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		j;
	int		k;
	int		l;
	char	*dest;

	i = -1;
	k = 0;
	dest = malloc(sizeof(*dest) * len_total(size, strs, sep));
	while (strs[++i] && i < size)
	{
		j = -1;
		while (strs[i][++j])
			dest[k++] = strs[i][j];
		l = -1;
		if (i < size - 1)
		{
			while (sep[++l])
				dest[k++] = sep[l];
		}
	}
	dest[k] = '\0';
	return (dest);
}

int		main(int argc, char **argv)
{
	char *sep;
	char *dest;

	sep = "000";
	argv[0] = "Wesh";
	argv[1] = "bonjour";
	argv[2] = "les";
	argv[3] = "amis, ";
	argv[4] = "ca";
	argv[5] = "va";
	argv[6] = "bien?";
	(void)argc;
	dest = ft_strjoin(3, argv, sep);
	printf("%s\n", dest);
	free(dest);
	return (0);
}
