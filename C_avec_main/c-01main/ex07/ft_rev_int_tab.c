/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 16:01:59 by tdayde            #+#    #+#             */
/*   Updated: 2020/08/15 12:43:26 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void ft_rev_int_tab(int *tab, int size)
{
	int i;
	int tmp;
	int j;

	i = 0;
	j = size - 1;
	while (i <= j)
	{
		tmp = tab[i];
		tab[i] = tab[j];
		tab[j] = tmp;
		i++;
		j--;
	}
}

int main(void)
{
	int T[]= {1, 2, 3, 4, 5};
	int i;

	i = 0;
	ft_rev_int_tab(T, 5);
	while (i < 5)
	{
		printf("%d",T[i]);
		i++;
	}
	return 0;
}
