/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadams <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 14:50:19 by oadams            #+#    #+#             */
/*   Updated: 2020/08/23 19:55:15 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		row_left(int **res, int *input, int y)
{
	int		box_seen;
	int		max_seen;
	int		x;

	box_seen = 0;
	max_seen = 0;
	x = 0;
	while (x < 4)
	{
		if (res[y][x] == 0)
			return (0);
		if (res[y][x] > max_seen)
		{
			max_seen = res[y][x];
			box_seen++;
		}
		x++;
	}
	if (box_seen != input[8 + y])
		return (1);
	return (0);
}

int		row_right(int **res, int *input, int y)
{
	int		box_seen;
	int		max_seen;
	int		x;

	x = 3;
	max_seen = 0;
	box_seen = 0;
	while (x >= 0)
	{
		if (res[y][x] == 0)
			return (0);
		if (res[y][x] > max_seen)
		{
			max_seen = res[y][x];
			box_seen++;
		}
		x--;
	}
	if (box_seen != input[12 + y])
		return (1);
	return (0);
}

int		col_up(int **res, int *input, int x)
{
	int		box_seen;
	int		max_seen;
	int		y;

	box_seen = 0;
	max_seen = 0;
	y = 0;
	while (y < 4)
	{
		if (res[y][x] == 0)
			return (0);
		if (res[y][x] > max_seen)
		{
			max_seen = res[y][x];
			box_seen++;
		}
		y++;
	}
	if (box_seen != input[x])
		return (1);
	return (0);
}

int		col_down(int **res, int *input, int x)
{
	int		box_seen;
	int		max_seen;
	int		y;

	y = 3;
	max_seen = 0;
	box_seen = 0;
	while (y >= 0)
	{
		if (res[y][x] == 0)
			return (0);
		if (res[y][x] > max_seen)
		{
			max_seen = res[y][x];
			box_seen++;
		}
		y--;
	}
	if (box_seen != input[x + 4])
		return (1);
	return (0);
}

int		no_match_input(int **res, int *input, int i)
{
	int		x;
	int		y;

	x = i % 4;
	y = i / 4;
	if (row_left(res, input, y)
			|| row_right(res, input, y)
			|| col_up(res, input, x)
			|| col_down(res, input, x))
		return (1);
	return (0);
}
