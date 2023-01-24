/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prints.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 11:34:16 by francoma          #+#    #+#             */
/*   Updated: 2022/12/11 08:52:04 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "functions.h"

void	print_dict(t_dict_entry *dict)
{
	while (dict->val)
	{
		printf("%u:\t\t%s\n", dict->key, dict->val);
		dict++;
	}
}
