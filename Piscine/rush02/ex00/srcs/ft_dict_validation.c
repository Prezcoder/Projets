/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_validation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 14:57:07 by francoma          #+#    #+#             */
/*   Updated: 2022/12/11 12:20:19 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

char	*ft_is_valid_entry_format(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\n')
		return (++str);
	while (str[i] != ' ' && str[i] != ':')
		if (!(str[i] >= '0' && str[i++] <= '9'))
			return (NULL);
	while (str[i] != ':')
		if (str[i++] != ' ')
			return (NULL);
	i++;
	while (!(str[i] >= 33 && str[i] <= 126))
		if (str[i++] != ' ')
			return (NULL);
	while (str[i] != '\n')
		if (!(str[i] >= 32 && str[i++] <= 126))
			return (NULL);
	return (++str + i);
}

int	ft_is_valid_dict_format(char *str)
{
	while (*str)
	{
		str = ft_is_valid_entry_format(str);
		if (!str)
			return (0);
	}
	return (1);
}

int	ft_is_in_dict(unsigned int nb, t_dict_entry	*dict)
{
	int	i;

	i = 0;
	while (dict[i].val)
	{
		if (nb == dict[i].key)
			return (1);
		i++;
	}
	return (0);
}

int	ft_is_useful_entry(char *str, t_dict_entry	*dict)
{
	unsigned int	nb;

	(void) dict;
	if (*str == '\n' || !ft_valid_unsigned_int(str))
		return (0);
	nb = ft_atoi(str);
	if (!ft_is_in_dict(nb, dict))
	{
		if (nb <= 19)
			return (1);
		if (nb <= 100 && nb % 10 == 0)
			return (1);
		if (nb == 1000 || nb == 1000000 || nb == 1000000000)
			return (1);
	}
	return (0);
}

int	ft_dict_is_complete(t_dict_entry	*dict)
{
	int	i;

	i = 0;
	while (dict[i].val)
		i++;
	return (i == DICT_SIZE);
}
