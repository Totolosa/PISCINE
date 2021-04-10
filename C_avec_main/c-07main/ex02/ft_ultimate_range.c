/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 10:29:34 by tdayde            #+#    #+#             */
/*   Updated: 2020/08/25 21:41:29 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int i;
	int *tab;

	i = 0;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	tab = malloc(sizeof(*tab) * (max - min));
	while (i < (max - min))
	{
		tab[i] = min + i;
		i++;
	}
	*range = tab;
	return (max - min);
}

int		main(void)
{
	int *tab;
	int i;
	int min = -5;
	int max = 5;

	i = 0;
	ft_ultimate_range(&tab, min, max);
	while (i < max - min)
	{
		printf("%d\n", tab[i]);
		i++;
	}
	return (0);
}
