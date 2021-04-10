/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudet- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 14:07:18 by lgaudet-          #+#    #+#             */
/*   Updated: 2020/09/02 22:30:46 by lgaudet-         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "parser.h"
#include "ft_atoi.h"

void	read_file(int file, char **str)
{
	int		size;
	int		i;
	int		ret;
	char	tmp[BUFF_SIZE];
	char	*res;

	*str = malloc(sizeof(char*));
	(*str)[0] = 0;
	size = 1;
	while ((ret = read(file, tmp, BUFF_SIZE)))
	{
		res = malloc((size * BUFF_SIZE + 1) * sizeof(char*));
		i = -1;
		while ((*str)[++i])
			res[i] = (*str)[i];
		i = -1;
		while (++i < ret)
			res[i + (size - 1) * BUFF_SIZE] = tmp[i];
		free(*str);
		*str = res;
		size++;
	}
	(*str)[i + size * BUFF_SIZE] = 0;
}

int		verif_param(char **buff, t_info_map *info)
{
	int	i;

	i = 0;
	while ((*buff)[i] != '\n' && (*buff)[i] != 0)
		i++;
	i--;
	if (i < 1)
		return (0);
	info->str[3] = 0;
	info->str[2] = (*buff)[i--];
	info->str[1] = (*buff)[i--];
	info->str[0] = (*buff)[i];
	(*buff)[i] = 0;
	if ((info->row = ft_atoi(*buff)) <= 0)
		return (0);
	if (info->str[0] == info->str[1] || info->str[0] == info->str[2]
			|| info->str[1] == info->str[2])
		return (0);
	*buff += i + 4;
	return (1);
}

int		read_from_buffer(char *buff, char **res, t_info_map info)
{
	int		i;
	int		j;
	int		buff_i;

	i = 0;
	j = 0;
	buff_i = 0;
	while (buff[buff_i])
	{
		if (!ft_char_is_in_set(buff[buff_i], info.str) ||
				j >= info.col || i >= info.row)
			return (0);
		res[i][j++] = buff[buff_i++];
		if (buff[buff_i] == '\n')
		{
			buff_i++;
			i++;
			if (j != info.col)
				return (0);
			j = 0;
		}
	}
	return (i == info.row);
}

int		parse_init(int file, t_info_map *info, char **buff)
{
	if ((*buff = malloc((BUFF_SIZE + 1) * sizeof(char*))) == NULL)
		return (0);
	read_file(file, buff);
	if (!verif_param(buff, info))
		return (0);
	return (1);
}

int		parse(int file, char ***res, t_info_map *info)
{
	int			i;
	char		*buff;

	*res = malloc(0);
	if (!parse_init(file, info, &buff))
		return (0);
	info->col = 0;
	while (buff[info->col] != '\n' && buff[info->col])
		info->col++;
	if (info->col < 1 || (*res = malloc((info->row) * sizeof(char **))) == NULL)
		return (0);
	i = -1;
	while (++i < info->row)
		if (((*res)[i] = malloc(info->col * sizeof(char *))) == NULL)
			return (0);
	if (!read_from_buffer(buff, *res, *info))
		return (0);
	return (1);
}
