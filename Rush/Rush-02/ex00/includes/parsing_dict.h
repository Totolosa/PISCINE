/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_dict.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 08:55:04 by nvu               #+#    #+#             */
/*   Updated: 2020/08/30 21:28:06 by nvu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_DICT_H
# define PARSING_DICT_H

int			ft_gt_space(int *i, char *str);
int			ft_check_file(char *str);
void		ft_fill_struct(t_dict *dict, char *str);
int			ft_malloc_struct(t_dict *dict, int j, int nbr, int str);
int			ft_measure_struct(t_dict *dict, char *str);
t_dict		*ft_create_dict(char *str);
char		*ft_readncreate_str(char *ref_dict);
t_dict		*ft_parsing_dict(char *ref_dict, int *j);
void		ft_free_dict(t_dict *dict, int *j);

#endif
