/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 20:22:34 by tdayde            #+#    #+#             */
/*   Updated: 2020/08/19 22:00:55 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	int res;

	res = 1;
	if (nb == 0)
		return (1);
	if (nb < 0)
		return (0);
	while (nb != 0)
	{
		res = res * nb;
		nb--;
	}
	return (res);
}

int	main(void)
{
	printf("%d", ft_iterative_factorial(6));
	return (0);
}
