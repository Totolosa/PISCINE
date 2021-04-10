/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 14:02:57 by tdayde            #+#    #+#             */
/*   Updated: 2020/08/27 23:43:59 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "ft_stock_str.h"

int					len(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char				*ft_strdup(char *src)
{
	int		i;
	char	*dest;

	i = 0;
	dest = malloc(sizeof(*dest) * (len(src) + 1));
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*tab;

	(void)av;
	i = 0;
	tab = malloc(sizeof(t_stock_str) * (ac + 1));
	if (tab == 0)
		return (tab);
	while (i < ac)
	{
		tab[i].size = len(av[i]);
		tab[i].str = av[i];
		tab[i].copy = ft_strdup(av[i]);
		i++;
	}
	tab[i].str = 0;
	return (tab);
}

void				ft_putstr(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		write(1, &str[i], 1);
}

void				ft_putnbr(int nbr)
{
	int i;

	i = 0;
	if (nbr >= 0 && nbr <= 9)
	{
		nbr = nbr + '0';
		write(1, &nbr, 1);
	}
	else if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
}

void				ft_show_tab(struct s_stock_str *par)
{
	int i;

	i = 0;
	while (par[i].str != 0)
	{
		ft_putstr(par[i].str);
		write(1, "\n", 1);
		ft_putnbr(par[i].size);
		write(1, "\n", 1);
		ft_putstr(par[i].copy);
		write(1, "\n", 1);
		i++;
	}
}

int					main(void)
{
	char *av[5] = {"abvnoerveoibjep", "-67", "756", "ole", "-5o"};
	t_stock_str *tab;

	tab = ft_strs_to_tab(5, av);
	ft_show_tab(tab);
	tab[0].copy = "CACA";
	ft_show_tab(tab);
	return (0);
}
