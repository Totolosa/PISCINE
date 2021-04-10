/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 15:41:25 by tdayde            #+#    #+#             */
/*   Updated: 2020/08/14 10:37:59 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar_abc(char a, char b, char c)
{
	if (a < b && b < c)
	{
		write(1, &a, 1);
		write(1, &b, 1);
		write(1, &c, 1);
		if (a != 55)
		{
			write(1, ", ", 2);
		}
	}
}

void	ft_print_comb(void)
{
	int a;
	int b;
	int c;

	a = 48;
	b = 48;
	c = 48;
	while (a <= 55)
	{
		while (b <= 57)
		{
			while (c <= 57)
			{
				ft_putchar_abc(a, b, c);
				c++;
			}
			c = 48;
			b++;
		}
		b = 48;
		a++;
	}
}
