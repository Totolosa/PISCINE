/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dict.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 08:35:49 by nvu               #+#    #+#             */
/*   Updated: 2020/08/30 21:26:42 by nvu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/classic.h"
#include "includes/tools.h"
#include "includes/check_dict.h"

char			**ft_init_tab(void)
{
	int			i;
	char		**ref;

	ref = malloc(sizeof(char *) * 41);
	if (ref == NULL)
		return (NULL);
	i = -1;
	while (++i < 42)
	{
		ref[i] = malloc(sizeof(char) * 38);
		if (ref[i] == NULL)
		{
			while (--i >= 0)
				free(ref[i]);
			free(ref);
			return (NULL);
		}
	}
	i = ft_init_tab2(ref);
	ft_init_tab3(ref, i);
	return (ref);
}

int				ft_init_tab2(char **ref)
{
	int			i;

	i = 0;
	while (i < 10)
	{
		ref[i][0] = i + '0';
		ref[i++][1] = '\0';
	}
	while (i < 20)
	{
		ref[i][0] = '1';
		ref[i][1] = i + '0' - 10;
		ref[i++][2] = '\0';
	}
	while (i < 28)
	{
		ref[i][0] = i + '0' - 18;
		ref[i][1] = '0';
		ref[i++][2] = '\0';
	}
	return (i);
}

void			ft_init_tab3(char **ref, int i)
{
	int			j;
	int			k;

	ref[i][0] = '1';
	ref[i][1] = '0';
	ref[i][2] = '0';
	ref[i][3] = '\0';
	k = 2;
	while (++i < 41)
	{
		ref[i][0] = '1';
		j = 1;
		while (j < k)
		{
			ref[i][j++] = '0';
			ref[i][j++] = '0';
			ref[i][j++] = '0';
		}
		ref[i][j] = '\0';
		k += 3;
	}
}

int				ft_check_dict(t_dict *dict, char **ref, int *k)
{
	int			i;
	int			j;

	i = 0;
	while (i < (*k))
	{
		j = -1;
		while (++j < 41)
		{
			if (ft_strcmp(dict[i].nbr, ref[j]) == 0)
			{
				ref[j][0] = 'O';
				ref[j][1] = 'K';
				ref[j][2] = '\0';
				break ;
			}
		}
		i++;
	}
	if (ft_testnfree_ref(ref))
		return (1);
	return (0);
}

int				ft_testnfree_ref(char **ref)
{
	int		i;
	int		check;

	check = 0;
	i = -1;
	while (++i < 41)
	{
		if (ref[i][0] != 'O')
		{
			check = 1;
		}
	}
	i = 0;
	while (i < 41)
	{
		free(ref[i]);
		i++;
	}
	free(ref);
	return (check);
}
