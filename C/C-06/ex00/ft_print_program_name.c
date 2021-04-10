/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 19:08:14 by tdayde            #+#    #+#             */
/*   Updated: 2020/08/24 11:12:34 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	char	*prog_name;
	int		i;

	(void)argc;
	i = 0;
	prog_name = argv[0];
	while (prog_name[i] != '\0')
	{
		write(1, &prog_name[i], 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
