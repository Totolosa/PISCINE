/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 09:51:38 by tdayde            #+#    #+#             */
/*   Updated: 2020/08/25 10:16:04 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		str_len(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i + 1);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*dest;

	i = 0;
	dest = malloc(sizeof(*dest) * str_len(src));
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	if (src[i] == 0)
		dest[i] = 0;
	return (dest);
}

int		main(void)
{
	char src[] = "Bonjour";
	char *dest;

	dest = ft_strdup(src);
	printf("%s\n", src);
	printf("%s\n", dest);
	return (0);
}
