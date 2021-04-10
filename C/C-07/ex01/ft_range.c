/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 10:29:34 by tdayde            #+#    #+#             */
/*   Updated: 2020/08/25 14:26:42 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		count_nb_int(int min, int max)
{
	int nb_int;

	nb_int = max - min;
	return (nb_int);
}

int		*ft_range(int min, int max)
{
	int i;
	int *res;

	i = 0;
	if (min >= max)
	{
		res = NULL;
		return (res);
	}
	res = malloc(sizeof(*res) * count_nb_int(min, max));
	while (i < count_nb_int(min, max))
	{
		res[i] = min + i;
		i++;
	}
	return (res);
}
