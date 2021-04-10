/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 14:29:06 by tdayde            #+#    #+#             */
/*   Updated: 2020/08/15 16:13:51 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int i;
	int j;

	i = 0;
	while (i <= size - 1)
	{
		j = 0;
		while (j <= size - 2)
		{
			if (tab[j] > tab[j + 1])
			{
				ft_swap(&tab[j], &tab[j + 1]);
			}
			j++;
		}
		i++;
	}
}

int main(void)
{
	int T[]= {134, -45, 5, 2874, -2, 56};
	int i;

	i = 0;
	ft_sort_int_tab(T, 6);
	while (i < 6)
	{
		printf("%d",T[i]);
		i++;
	}
	return 0;
}
