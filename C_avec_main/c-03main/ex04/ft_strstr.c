/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 14:44:22 by tdayde            #+#    #+#             */
/*   Updated: 2020/08/18 19:55:32 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	int j;

	if (*to_find == '\0')
		return (str);
	while (*str)
	{
		j = 0;
		while (str[j] == to_find[j])
		{
			if (to_find[j + 1] == '\0')
				return (str);
			j++;
		}
		str++;
	}
	return (0);
}

int		main(void)
{
	char str[] = "Commeeeeent tu vas? Ca fai plaiz";
	char to_find[] = "en";

	printf("%s\n", ft_strstr(str, to_find));
	printf("%s\n", strstr(str, to_find));
	return (0);
}
