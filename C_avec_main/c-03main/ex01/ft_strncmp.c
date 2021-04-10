/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 14:44:22 by tdayde            #+#    #+#             */
/*   Updated: 2020/08/18 10:02:46 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int i;

	i = 0;
	while (s1[i] != '\0' && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (s1[i] == '\0' && s2[i] != '\0')
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}

int	main(void)
{
	char str1[50];
	char str2[50];
	int moi;
	int bibli;

	strcpy(str1, "abcde");
	strcpy(str2, "abcdewvoijerv894f");
	moi = ft_strncmp(str1, str2, 0);
	bibli = strncmp(str1, str2, 0);
	
	printf("%d\n", moi);
	printf("%d\n", bibli);
	if(bibli < 0) {
		printf("str1 is less than str2");
	} else if(bibli > 0) {
		printf("str2 is less than str1");
	} else {
		printf("str1 is equal to str2");
	}

	return(0);
}
