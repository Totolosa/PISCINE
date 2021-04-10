/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 18:30:09 by nvu               #+#    #+#             */
/*   Updated: 2020/09/01 09:43:00 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/classic.h"
#include "includes/tools.h"
#include "includes/parsing_dict.h"
#include "includes/check_dict.h"
#include "includes/print_input.h"

void			ft_free_all(t_dict *dict, int *j)
{
	ft_free_dict(dict, j);
}

int				check_input(char *input)
{
	int i;

	i = -1;
	while (input[++i])
		if (input[i] < '0' || input[i] > '9' || ft_strlen(input) > 39)
			return (0);
	return (1);
}

int				main(int ac, char **av)
{
	t_dict		*dict;
	char		*ref_dict;
	int			j;

	if (ac == 3)
		ref_dict = av[1];
	else if (ac == 2)
		ref_dict = "./dicts/numbers.dict";
	else
		return (1);
	dict = ft_parsing_dict(ref_dict, &j);
	if (dict == NULL || (ft_check_dict(dict, ft_init_tab(), &j)))
	{
		ft_putstr("Dict Error\n");
		return (1);
	}
	if (check_input(av[ac - 1]))
		print_input(dict, av[ac - 1]);
	else
		ft_putstr("Error\n");
	ft_free_dict(dict, &j);
	return (0);
}
