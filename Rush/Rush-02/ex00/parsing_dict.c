/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_dict.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 08:44:08 by nvu               #+#    #+#             */
/*   Updated: 2020/08/30 22:05:35 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/classic.h"
#include "includes/tools.h"
#include "includes/parsing_dict.h"

int			ft_measure_struct(t_dict *dict, char *str)
{
	int			i;
	int			nbr_len;
	int			str_len;
	int			j;

	i = -1;
	j = 0;
	while (str[++i])
	{
		while (str[i--] != '\n')
		{
			nbr_len = 0;
			str_len = 0;
			while (str[++i] && str[i] != ' ' && str[i] >= 48 && str[i] <= 57)
				nbr_len++;
			ft_gt_space(&i, str);
			while (str[++i] && str[i] != '\n')
				str_len++;
			if (ft_malloc_struct(dict, j, nbr_len, str_len))
				return (0);
			j++;
		}
		i++;
	}
	return (j);
}

t_dict		*ft_create_dict(char *str)
{
	int			dict_len;
	int			i;
	t_dict		*dict;

	i = 0;
	dict_len = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			dict_len++;
		i++;
	}
	dict = malloc(sizeof(t_dict) * (dict_len + 1));
	if (dict == NULL)
	{
		free(str);
		return (NULL);
	}
	return (dict);
}

char		*ft_readncreate_str(char *ref_dict)
{
	int			str_len;
	char		c;
	int			i;
	int			fd;
	char		*str;

	fd = open(ref_dict, O_RDONLY);
	if (fd == -1)
		return (NULL);
	str_len = 0;
	while (read(fd, &c, 1) > 0)
		str_len += 1;
	close(fd);
	str = malloc(sizeof(char) * (str_len + 1));
	if (str == NULL)
		return (NULL);
	fd = open(ref_dict, O_RDONLY);
	if (fd == -1)
		return (NULL);
	i = 0;
	while (read(fd, &c, 1) > 0)
		str[i++] = c;
	str[i] = '\0';
	close(fd);
	return (str);
}

t_dict		*ft_parsing_dict(char *ref_dict, int *j)
{
	char		*str;
	t_dict		*dict;

	str = ft_readncreate_str(ref_dict);
	if (str == NULL)
		return (NULL);
	if (ft_check_file(str))
	{
		free(str);
		return (NULL);
	}
	dict = ft_create_dict(str);
	if (dict == NULL)
		return (NULL);
	(*j) = ft_measure_struct(dict, str);
	if ((*j) == 0)
	{
		free(str);
		free(dict);
		return (NULL);
	}
	ft_fill_struct(dict, str);
	free(str);
	return (dict);
}
