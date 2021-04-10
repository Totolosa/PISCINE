/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 17:33:50 by tdayde            #+#    #+#             */
/*   Updated: 2020/08/17 11:36:34 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

char	*ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int 	main()
{
	char src[] = "Aller le stade Toulousain!";
	char dest[100] = {"qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq"};

	printf("%s", ft_strcpy(dest, src));
	return 0;
}
