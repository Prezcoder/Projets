/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 06:42:13 by francoma          #+#    #+#             */
/*   Updated: 2022/12/11 16:56:40 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

t_dict_entry	find_dict_entry(t_uint nb, t_dict_entry *dict)
{
	int	i;

	i = -1;
	while (dict[++i].val)
		if (nb == dict[i].key || nb / dict[i].key > 0)
			break ;
	return (dict[i]);
}

void	write_key_qty(t_uint qty, t_dict_entry *dict)
{
	spell_number(qty, dict);
	ft_putstr(" ");
}

void	write_remainder(t_uint remainder, t_uint key, t_dict_entry *dict)
{
	if (key < 100)
		ft_putstr("-");
	else
		ft_putstr(" ");
	spell_number(remainder, dict);
}

void	spell_number(long nb, t_dict_entry *dict)
{
	t_dict_entry	entry;
	t_uint			key_qty;
	t_uint			remainder;

	if (nb < 0)
	{
		nb *= -1;
		ft_putstr("minus ");
	}
	key_qty = 0;
	remainder = 0;
	entry = find_dict_entry(nb, dict);
	if (nb == entry.key && entry.key < 100)
		ft_putstr(entry.val);
	else
	{
		key_qty = nb / entry.key;
		if (entry.key >= 100)
			write_key_qty(key_qty, dict);
		ft_putstr(entry.val);
		remainder = nb - (key_qty * entry.key);
		if (remainder > 0)
			write_remainder(remainder, entry.key, dict);
	}
}
