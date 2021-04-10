/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 15:37:12 by tdayde            #+#    #+#             */
/*   Updated: 2020/08/18 23:54:36 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int		is_num(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int		isaspace(char c)
{
	if (c == ' ' || c == '\f' || c == '\n' || c == '\r'
											|| c == '\t' || c == '\v')
		return (1);
	else
		return (0);
}

int		ft_atoi(char *str)
{
	int i;
	int res;
	int signe;

	i = 0;
	res = 0;
	signe = 1;
	while (isaspace(str[i]))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe = signe * -1;
		i++;
	}
	while (is_num(str[i]))
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	res = res * signe;
	return (res);
}

int		main(void)
{
	char str[] = " ---+--+1234473ab567";

	printf("%d\n", ft_atoi(str));
	printf("%d", atoi(str));
	return (0);
}
