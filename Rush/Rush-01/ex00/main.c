/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 19:29:35 by tdayde            #+#    #+#             */
/*   Updated: 2020/08/23 21:44:33 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "set_input_res.h"
#include "solve_gen.h"
#include "error_input.h"

int	main(int argc, char **argv)
{
	int i;
	int **res;
	int *input;

	i = 0;
	res = (int **)malloc(sizeof(*res) * 4);
	while (i < 4)
	{
		res[i] = (int *)malloc(sizeof(*res) * 4);
		i++;
	}
	if (argc == 2)
	{
		input = argv_to_input(argv[1]);
		if (input[0] != 0)
		{
			res = fill_res(res, 0);
			if (solve_gen(res, input, 0, 0) == 0)
				write(1, "Error\n", 6);
			return (0);
		}
	}
	free(res);
	write(1, "Error\n", 6);
	return (0);
}
