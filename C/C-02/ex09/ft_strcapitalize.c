/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdayde <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 23:56:37 by tdayde            #+#    #+#             */
/*   Updated: 2020/08/17 16:59:22 by tdayde           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_str_is_alpha(char c)
{
	if (c < 'A' || c > 'z')
	{
		return (0);
	}
	if (c > 'Z' && c < 'a')
	{
		return (0);
	}
	return (1);
}

int		ft_str_is_numeric(char c)
{
	if (c < '0' || c > '9')
	{
		return (0);
	}
	return (1);
}

int		ft_str_is_lowercase(char c)
{
	if (c < 'a' || c > 'z')
	{
		return (0);
	}
	return (1);
}

int		ft_str_is_uppercase(char c)
{
	if (c < 'A' || c > 'Z')
	{
		return (0);
	}
	return (1);
}

char	*ft_strcapitalize(char *str)
{
	int i;
	int firstletter;

	i = 0;
	firstletter = 1;
	while (str[i] != '\0')
	{
		if (ft_str_is_lowercase(str[i]) == 1 && firstletter == 1)
		{
			str[i] = str[i] - 32;
			firstletter = 0;
		}
		else if (ft_str_is_numeric(str[i]) == 1 && firstletter == 1)
			firstletter = 0;
		else if (ft_str_is_uppercase(str[i]) == 1 && firstletter == 0)
			str[i] = str[i] + 32;
		else if (ft_str_is_uppercase(str[i]) == 1 && firstletter == 1)
			firstletter = 0;
		else if (!(ft_str_is_alpha(str[i])) && !(ft_str_is_numeric(str[i])))
			firstletter = 1;
		i++;
	}
	return (str);
}
