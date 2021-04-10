/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creation_res.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 21:39:44 by tdayde            #+#    #+#             */
/*   Updated: 2020/08/23 19:41:00 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_INPUT_RES_H
# define SET_INPUT_RES_H

void	print_res(int **res);

int		**fill_res(int **res, int nb);

int		*argv_to_input(char *argv);

#endif
