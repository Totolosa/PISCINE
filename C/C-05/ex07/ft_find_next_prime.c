/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 19:02:26 by tdayde            #+#    #+#             */
/*   Updated: 2020/08/24 15:38:26 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_is_prime(int nb)
{
	long int i;

	i = 5;
	if (nb <= 1)
		return (0);
	else if (nb == 2 || nb == 3)
		return (1);
	if (!(nb % 2 == 0 || nb % 3 == 0))
	{
		while (i * i <= nb)
		{
			if ((nb % i == 0) || ((nb % (i + 2)) == 0))
				return (0);
			i += 6;
		}
		return (1);
	}
	return (0);
}

int	ft_find_next_prime(int nb)
{
	long int j;

	j = nb;
	if (nb <= 1)
		return (2);
	while ((ft_is_prime(j) == 0))
		j++;
	return (j);
}
