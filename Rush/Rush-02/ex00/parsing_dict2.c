/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_dict2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 19:21:43 by nvu               #+#    #+#             */
/*   Updated: 2020/08/30 21:26:08 by nvu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/classic.h"
#include "includes/tools.h"
#include "includes/parsing_dict.h"

int				ft_gt_space(int *i, char *str)
{
	while (str[*i] == ' ')
		(*i)++;
	if (str[*i] == ':')
		(*i)++;
	else if (str[*i] != '\n')
		return (1);
	while (str[*i] == ' ')
		(*i)++;
	if (str[*i] != '\n')
		(*i)--;
	return (0);
}

int				ft_check_file(char *str)
{
	int			i;

	i = 0;
	while (str[i])
	{
		while (str[i] >= '0' && str[i] <= '9')
			i++;
		if (ft_gt_space(&i, str))
			return (1);
		while (str[i] != '\n')
			i++;
		if (str[i] == '\n')
			i++;
	}
	return (0);
}

void			ft_fill_struct(t_dict *dict, char *str)
{
	int			i;
	int			j;
	int			k;

	i = -1;
	j = 0;
	while (str[++i])
	{
		while (str[i--] != '\n')
		{
			k = 0;
			while (str[++i] >= 48 && str[i] <= 57)
				dict[j].nbr[k++] = str[i];
			dict[j].nbr[k] = '\0';
			ft_gt_space(&i, str);
			k = 0;
			while (str[++i] != '\n')
				dict[j].str[k++] = str[i];
			dict[j].str[k] = '\0';
			j++;
		}
		i++;
	}
}

int				ft_malloc_struct(t_dict *dict, int j, int nbr, int str)
{
	dict[j].nbr = malloc(sizeof(char) * (nbr + 1));
	dict[j].str = malloc(sizeof(char) * (str + 1));
	if (dict[j].nbr == NULL || dict[j].str == NULL)
	{
		if (dict[j].str == NULL)
			free(dict[j].nbr);
		while (--j >= 0)
		{
			free(dict[j].nbr);
			free(dict[j].str);
		}
		return (1);
	}
	return (0);
}

void			ft_free_dict(t_dict *dict, int *j)
{
	while (--(*j) >= 0)
	{
		free(dict[*j].nbr);
		free(dict[*j].str);
	}
	free(dict);
}
