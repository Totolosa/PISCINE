/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creation_tab_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 15:24:16 by tdayde            #+#    #+#             */
/*   Updated: 2020/09/02 16:11:32 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "resolve.h"

int			**create_tab_int(t_info_map info_map)
{
	int i;
	int **tab_int;

	i = -1;
	tab_int = malloc(sizeof(*tab_int) * info_map.row);
	if (tab_int == NULL)
	{
		free(tab_int);
		return (NULL);
	}
	while (++i < info_map.col)
	{
		tab_int[i] = malloc(sizeof(**tab_int) * info_map.col);
		if (tab_int[i] == NULL)
		{
			free(tab_int);
			return (NULL);
		}
	}
	return (tab_int);
}

int			**fill_tab_int(int **tab_int, char **tab_char, t_info_map info_map)
{
	int i;
	int j;

	i = 0;
	while (i < info_map.row)
	{
		j = 0;
		while (j < info_map.col)
		{
			if (tab_char[i][j] == info_map.str[0])
				tab_int[i][j] = 0;
			if (tab_char[i][j] == info_map.str[1])
				tab_int[i][j] = -1;
			j++;
		}
		i++;
	}
	return (tab_int);
}

int			**fill_row_1(int **tab, t_info_map map, t_sq_max *sq_max, int *em)
{
	int i;
	int j;

	i = -1;
	j = -1;
	while (++j < map.col)
	{
		if (tab[0][j] == 0)
		{
			tab[0][j] = 1;
			if (*em == 0)
			{
				sq_max->y = j;
				sq_max->max = 1;
				*em = 1;
			}
		}
	}
	return (tab);
}

int			**fill_col_1(int **tab, t_info_map map, t_sq_max *sq_max, int *em)
{
	int i;
	int j;

	i = -1;
	j = -1;
	while (++i < map.row)
	{
		if (tab[i][0] == 0)
		{
			tab[i][0] = 1;
			if (*em == 0)
			{
				sq_max->x = i;
				sq_max->max = 1;
				*em = 1;
			}
		}
	}
	return (tab);
}
