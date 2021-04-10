/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 15:37:12 by tdayde            #+#    #+#             */
/*   Updated: 2020/08/18 23:56:10 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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
