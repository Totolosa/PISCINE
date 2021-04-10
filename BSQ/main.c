/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 15:07:21 by tdayde            #+#    #+#             */
/*   Updated: 2020/09/02 19:55:40 by lgaudet-         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "resolve.h"
#include "parser.h"

void	reso_map(int file)
{
	char		**tab_char;
	t_info_map	info_map;

	if (!parse(file, &tab_char, &info_map))
	{
		write(1, "map error\n", 10);
	}
	else if (!resolve(tab_char, info_map))
		write(1, "Malloc error\n", 13);
	free(tab_char);
}

int		main(int argc, char **argv)
{
	int		i;
	int		file;

	i = 1;
	if (argc == 1)
		reso_map(0);
	while (i < argc)
	{
		file = open(argv[i], O_RDONLY);
		if (file < 0)
			write(1, "Cannot open file", 16);
		reso_map(file);
		close(file);
		i++;
	}
	return (0);
}
