/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 21:23:50 by tdayde            #+#    #+#             */
/*   Updated: 2020/09/03 21:41:47 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int is_printed_both(char *str, char c)
{
	int i;

	i = -1;
	while (str[++i])
		if (c == str[i])
			return (1);
	return (0);
}

int is_printed_before(char *str, char c, int pos_max)
{
	int i;

	i = -1;
	while (++i < pos_max)
		if (c == str[i])
			return (0);
	return (1);
}
		
int main(int argc, char **argv)
{
	int i;

	i = -1;
	if (argc == 3)
		while (argv[1][++i])
			if (is_printed_both(argv[2], argv[1][i]) && is_printed_before(argv[1], argv[1][i], i))
				write(1, &argv[1][i], 1);
	return (0);
}
