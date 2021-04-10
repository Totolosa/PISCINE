/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dict.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 08:38:09 by nvu               #+#    #+#             */
/*   Updated: 2020/08/30 19:53:26 by nvu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_DICT_H
# define CHECK_DICT_H

char		**ft_init_tab(void);
int			ft_init_tab2(char **ref);
void		ft_init_tab3(char **ref, int i);
int			ft_check_dict(t_dict *dict, char **ref, int *k);
int			ft_testnfree_ref(char **ref);

#endif
