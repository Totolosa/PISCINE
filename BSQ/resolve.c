/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 15:03:37 by tdayde            #+#    #+#             */
/*   Updated: 2020/09/02 16:11:29 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "resolve.h"

int			min(int nbr1, int nbr2, int nbr3)
{
	int min;

	min = nbr1;
	if (min > nbr2)
		min = nbr2;
	if (min > nbr3)
		min = nbr3;
	return (min + 1);
}

t_sq_max	is_it_max(t_sq_max sq_max, int *square, t_sq_beside sq_beside)
{
	if (sq_beside.up >= 0 && sq_beside.left >= 0 && sq_beside.diag >= 0)
		*square = min(sq_beside.up, sq_beside.left, sq_beside.diag);
	else
		*square = 1;
	if (sq_max.max < *square)
	{
		sq_max.x = sq_beside.i;
		sq_max.y = sq_beside.j;
		sq_max.max = *square;
	}
	return (sq_max);
}

t_sq_max	find_square_max(int **tab_int, t_info_map info_map, t_sq_max sq_max)
{
	int			i;
	int			j;
	t_sq_beside	sq_beside;

	i = 0;
	while (++i < info_map.row)
	{
		j = 0;
		while (++j < info_map.col)
		{
			if (tab_int[i][j] == 0)
			{
				sq_beside.up = tab_int[i - 1][j];
				sq_beside.left = tab_int[i][j - 1];
				sq_beside.diag = tab_int[i - 1][j - 1];
				sq_beside.i = i;
				sq_beside.j = j;
				sq_max = is_it_max(sq_max, &tab_int[i][j], sq_beside);
			}
		}
	}
	return (sq_max);
}

void		print_tab(char **tab_char, t_info_map info_map, t_sq_max sq_max)
{
	int i;
	int j;

	i = -1;
	while (++i < sq_max.max)
	{
		j = -1;
		while (++j < sq_max.max)
			tab_char[sq_max.x - i][sq_max.y - j] = info_map.str[2];
	}
	i = -1;
	while (++i < info_map.row)
	{
		j = -1;
		while (++j < info_map.col)
			write(1, &tab_char[i][j], 1);
		write(1, "\n", 1);
	}
}

int			resolve(char **tab_char, t_info_map info_map)
{
	int			i;
	int			**tab_int;
	int			empty;
	t_sq_max	sq_max;

	i = 0;
	tab_int = create_tab_int(info_map);
	tab_int = fill_tab_int(tab_int, tab_char, info_map);
	if (tab_int == NULL)
		return (0);
	sq_max = (t_sq_max) {0, 0, 0};
	tab_int = fill_row_1(tab_int, info_map, &sq_max, &empty);
	tab_int = fill_col_1(tab_int, info_map, &sq_max, &empty);
	if (info_map.row > 1 && info_map.col > 1)
		sq_max = find_square_max(tab_int, info_map, sq_max);
	print_tab(tab_char, info_map, sq_max);
	free(tab_int);
	return (1);
}
