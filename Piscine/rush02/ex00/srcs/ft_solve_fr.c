/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_fr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 10:02:22 by francoma          #+#    #+#             */
/*   Updated: 2022/12/11 17:02:45 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

t_dict_entry	find_dict_entry_fr(t_uint nb, t_dict_entry *dict)
{
	int	i;

	i = -1;
	while (dict[++i].val)
		if (nb == dict[i].key
			|| (nb / dict[i].key > 0 && dict[i].key != 90 && dict[i].key != 70))
			break ;
	return (dict[i]);
}

void	write_key_qty_fr(t_uint qty, t_dict_entry *dict)
{
	spell_number_fr(qty, dict);
	ft_putstr(" ");
}

void	write_remainder_fr(t_uint remainder, t_uint key, t_dict_entry *dict)
{
	if (key < 100)
	{
		if (remainder == 1)
			ft_putstr(" et ");
		else
			ft_putstr("-");
	}
	else
		ft_putstr(" ");
	spell_number_fr(remainder, dict);
}

void	spell_number_fr(long nb, t_dict_entry *dict)
{
	t_dict_entry	entry;
	t_uint			key_qty;
	t_uint			remainder;

	if (nb < 0)
		ft_putstr("moins ");
	if (nb < 0)
		nb *= -1;
	key_qty = 0;
	remainder = 0;
	entry = find_dict_entry_fr(nb, dict);
	if (nb == entry.key && entry.key <= 1000)
		ft_putstr(entry.val);
	else
	{
		key_qty = nb / entry.key;
		if ((key_qty > 1 && entry.key >= 100) || entry.key >= 1000000)
			write_key_qty_fr(key_qty, dict);
		ft_putstr(entry.val);
		if (key_qty > 1 && (entry.key >= 1000000 || entry.key == 100))
			ft_putstr("s");
		remainder = nb - (key_qty * entry.key);
		if (remainder > 0)
			write_remainder_fr(remainder, entry.key, dict);
	}
}
