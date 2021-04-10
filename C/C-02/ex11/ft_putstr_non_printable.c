/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 19:16:58 by tdayde            #+#    #+#             */
/*   Updated: 2020/08/17 12:24:30 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_char_np(char c, const char *base)
{
	int div;
	int mod;

	div = (unsigned char)c / 16;
	mod = (unsigned char)c % 16;
	write(1, "\\", 1);
	write(1, &base[div], 1);
	write(1, &base[mod], 1);
}

void	ft_putstr_non_printable(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] > 31 && str[i] < 127)
			write(1, &str[i], 1);
		else
			print_char_np(str[i], "0123456789abcdef");
		i++;
	}
}
