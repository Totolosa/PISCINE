/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 23:50:27 by tdayde            #+#    #+#             */
/*   Updated: 2020/09/02 16:34:31 by lgaudet-         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef RESOLVE_H
# define RESOLVE_H

typedef	struct	s_info_map
{
	char	str[4];
	int		row;
	int		col;
}				t_info_map;

typedef	struct	s_sq_max
{
	int		x;
	int		y;
	int		max;
}				t_sq_max;

typedef	struct	s_sq_beside
{
	int		up;
	int		left;
	int		diag;
	int		i;
	int		j;
}				t_sq_beside;

int				resolve(char **tab_char, t_info_map info_map);
int				**create_tab_int(t_info_map info_map);
int				**fill_tab_int(int **tab_int,
		char **tab_char, t_info_map info_map);
int				**fill_row_1(int **tab, t_info_map map,
		t_sq_max *sq_max, int *em);
int				**fill_col_1(int **tab, t_info_map map,
		t_sq_max *sq_max, int *em);

#endif
