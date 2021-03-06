/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 15:16:30 by tdayde            #+#    #+#             */
/*   Updated: 2020/08/13 15:40:31 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_is_negative(int n)
{
	int sign;

	if (n < 0)
	{
		sign = 'N';
		write(1, &sign, 1);
	}
	else if (n >= 0)
	{
		sign = 'P';
		write(1, &sign, 1);
	}
}
