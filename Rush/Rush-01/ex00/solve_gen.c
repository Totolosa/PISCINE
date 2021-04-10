/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_voit_1_boite.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadams <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 18:23:21 by oadams            #+#    #+#             */
/*   Updated: 2020/08/23 21:44:10 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "error_input.h"
#include <stdio.h>
#include "set_input_res.h"

int		on_row_col(int **res, int i)
{
	int		x;
	int		y;
	int		k;

	y = i / 4;
	x = i % 4;
	k = 0;
	while (k < 4)
	{
		if (res[y][k] == res[y][x] && k != x)
			return (1);
		k++;
	}
	k = 0;
	while (k < 4)
	{
		if (res[k][x] == res[y][x] && k != y)
			return (1);
		k++;
	}
	return (0);
}

int		solve_gen(int **res, int *input, int i, int printed)
{
	int		y;
	int		x;
	int		k;

	if (i == 16)
	{
		if (res[0][0] != 0 && printed == 0)
		{
			print_res(res);
			printed = 1;
		}
		return (printed);
	}
	y = i / 4;
	x = i % 4;
	k = 1;
	while (k <= 4)
	{
		res[y][x] = k;
		if (no_match_input(res, input, i) == 0 && on_row_col(res, i) == 0)
			printed = solve_gen(res, input, i + 1, printed);
		k++;
	}
	res[y][x] = 0;
	return (printed);
}
