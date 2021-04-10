/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudet- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 18:44:51 by lgaudet-          #+#    #+#             */
/*   Updated: 2020/09/02 20:06:09 by lgaudet-         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_atoi.h"

int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int i;
	int neg;
	int res;

	i = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	neg = 0;
	while (str[i] && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			neg++;
		i++;
	}
	res = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		res *= 10;
		res += str[i] - '0';
		i++;
	}
	return ((neg % 2 == 1) ? -res : res);
}

int	ft_char_is_in_set(char c, char *charset)
{
	int	i;

	i = 0;
	while (i < 2)
		if (c == charset[i++])
			return (1);
	return (0);
}
