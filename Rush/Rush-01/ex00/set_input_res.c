/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creation_res.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 16:33:00 by tdayde            #+#    #+#             */
/*   Updated: 2020/08/23 21:24:37 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	ft_putchar(int nb)
{
	char c;

	c = nb + '0';
	write(1, &c, 1);
}

int		**fill_res(int **res, int nb)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			res[i][j] = nb;
			j++;
		}
		i++;
	}
	return (res);
}

void	print_res(int **res)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			ft_putchar(res[i][j]);
			if (j < 3)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int		*pair_is_1_to_4(int *input, int i_inp, char c)
{
	if (c >= '1' && c <= '4')
		input[i_inp] = c - '0';
	else
		input[0] = 0;
	return (input);
}

int		*argv_to_input(char *argv)
{
	int		*input;
	int		i;
	int		i_inp;

	i = 0;
	i_inp = 0;
	input = malloc(sizeof(*input) * 16);
	while (argv[i] != '\0')
	{
		if (i > 30)
		{
			input[0] = 0;
			return (input);
		}
		if (i % 2 == 0)
		{
			input = pair_is_1_to_4(input, i_inp, argv[i]);
			i_inp++;
		}
		if (i % 2 == 1 && argv[i] != ' ')
			input[0] = 0;
		i++;
	}
	return (input);
}
