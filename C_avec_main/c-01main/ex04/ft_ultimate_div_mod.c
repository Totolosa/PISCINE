/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 14:43:38 by tdayde            #+#    #+#             */
/*   Updated: 2020/08/14 14:58:23 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int tmpdiv;
	int tmpmod;

	tmpdiv = *a / *b;
	tmpmod = *a % *b;
	*a = tmpdiv;
	*b = tmpmod;
}
