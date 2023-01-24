/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 11:46:52 by francoma          #+#    #+#             */
/*   Updated: 2022/12/11 14:57:39 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

void	free_dict(t_dict_entry	*dict, int nb_on_heap, char *nb_str)
{
	int	i;

	i = 0;
	while (dict && dict[i].val)
	{
		free(dict[i].val);
		i++;
	}
	free(dict);
	if (nb_on_heap)
		free(nb_str);
}

int	ft_trim_space(char *dict_str)
{
	int	space;
	int	len;

	len = 0;
	space = 0;
	while (dict_str[len] != '\n')
	{
		if (dict_str[len] > 32 && dict_str[len] < 127)
		{
			space = 0;
		}
		else if (dict_str[len] == ' ')
		{
			space++;
		}
		len++;
	}	
	return (len - space);
}
