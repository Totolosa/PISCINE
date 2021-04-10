/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 14:44:22 by tdayde            #+#    #+#             */
/*   Updated: 2020/08/20 15:09:11 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <stdio.h>

int ft_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j] && j < size)
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i] = '\0';
	return (i + j);
}

int				main(void)
{
	char src[20] = "comment tu vas?";
	char dest[30] = "Salut, ";
	char destbibli[30] = "Salut, ";

	printf("%u\n", ft_strlcat(dest, src, 0));
	printf("%lu\n", strlcat(destbibli, src, 0));
	return (0);
}
