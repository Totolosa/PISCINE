/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 10:29:34 by tdayde            #+#    #+#             */
/*   Updated: 2020/08/25 14:30:18 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

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

int		main(void)
{
	int *res;
	int i;

	i = 0;
	res = ft_range(4, 4);
	while (i < count_nb_int(5, 4))
	{
		printf("%d\n", res[i]);
		i++;
	}
	return (0);
}
