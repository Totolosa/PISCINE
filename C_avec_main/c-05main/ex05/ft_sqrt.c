/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 15:16:37 by tdayde            #+#    #+#             */
/*   Updated: 2020/08/24 12:02:10 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_sqrt(int nb)
{
	int a;

	a = 1;
	if (nb <= 0)
		return (0);
	while (a < nb / a)
		a++;
	if (a * a == nb)
		return (a);
	else
		return (0);
}

int	main(void)
{
	printf("%d\n", ft_sqrt(0));
	printf("%d\n", ft_sqrt(9));
	printf("%d\n", ft_sqrt(3600));
	printf("%d\n", ft_sqrt(3601));
	return (0);
}
