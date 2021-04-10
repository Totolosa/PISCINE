/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 15:54:08 by tdayde            #+#    #+#             */
/*   Updated: 2020/09/03 21:20:02 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int is_print_before(char *str, char c, int pos_max)
{
	int j; 
	
	j = -1;
	while (++j < pos_max)
		if (c == str[j])
			return (0);
	return (1);
}

int main(int argc, char **argv)
{
	int i;
	int k;

	if (argc == 3)
	{
		i = -1;
		while (argv[1][++i])
			if (is_print_before(argv[1], argv[1][i], i))
				write(1, &argv[1][i], 1);
		k = -1;	
		while (argv[2][++k])
			if (is_print_before(argv[2], argv[2][k], k) && is_print_before(argv[1], argv[2][k], i))
				write(1, &argv[2][k], 1);
	}
	write(1, "\n", 1);
	return (0);
}
