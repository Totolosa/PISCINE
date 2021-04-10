/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 18:50:51 by tdayde            #+#    #+#             */
/*   Updated: 2020/08/30 23:40:22 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "./includes/tools.h"

void	print_power(t_dict *dict, char *input, int i)
{
	int j;
	int len_rest;

	j = 0;
	len_rest = ft_strlen(input) - i;
	while (ft_strlen(dict[j].nbr) != len_rest)
		j++;
	if (len_rest > 3)
	{
		if (i == 1)
			if (input[i - 1] != '0' || input[i] != '0')
				ft_putstr(dict[j].str);
		if (i >= 2)
			if (input[i - 2] != '0' || input[i - 1] != '0' || input[i] != '0')
				ft_putstr(dict[j].str);
		if (i == 0)
			ft_putstr(dict[j].str);
		if (input[i + 1] != '0' || input[i + 2] != '0' || input[i + 3] != '0')
			ft_putchar(' ');
	}
}

void	print_hundred(t_dict *dict, char *input, int i)
{
	int j;

	j = 0;
	while (dict[j].nbr[0] != input[i])
		j++;
	ft_putstr(dict[j].str);
	ft_putchar(' ');
	j = 0;
	while (ft_strcmp(dict[j].nbr, "100") != 0)
		j++;
	ft_putstr(dict[j].str);
	if ((input[i + 1] != '0' || input[i + 2] != '0')
			|| ft_strlen(input) - i > 3)
		ft_putchar(' ');
}

void	print_ten(t_dict *dict, char *input, int i)
{
	int j;

	j = 0;
	while (dict[j].nbr[0] != input[i] || dict[j].nbr[1] != '0')
		j++;
	if (input[i] != '1')
		ft_putstr(dict[j].str);
	else
	{
		while (dict[j].nbr[1] != input[i + 1])
			j++;
		ft_putstr(dict[j].str);
	}
	if (i != ft_strlen(input) - 2 || (input[i + 1] != '0' && input[i] != '1'))
		ft_putchar(' ');
}

void	print_unit(t_dict *dict, char c, char *input, int i)
{
	int j;

	j = 0;
	while (dict[j].nbr[0] != c || ft_strlen(dict[j].nbr) != 1)
		j++;
	ft_putstr(dict[j].str);
	if (i != ft_strlen(input) - 1)
		ft_putchar(' ');
}

void	print_input(t_dict *dict, char *input)
{
	int i;
	int cpt;

	cpt = 0;
	i = 0;
	while (input[i])
	{
		if (input[i] == '0')
			cpt++;
		if ((ft_strlen(input) - i) % 3 == 0 && input[i] != '0')
			print_hundred(dict, input, i);
		if ((ft_strlen(input) - i) % 3 == 2 && input[i] != '0')
			print_ten(dict, input, i);
		if ((ft_strlen(input) - i) % 3 == 1)
		{
			if ((i != 0 && input[i - 1] != '1' && input[i] != '0')
											|| (i == 0 && input[i] != '0'))
				print_unit(dict, input[i], input, i);
			if (ft_strlen(input) == cpt)
				print_unit(dict, '0', input, i);
			if (cpt != i + 1)
				print_power(dict, input, i);
		}
		i++;
	}
}
