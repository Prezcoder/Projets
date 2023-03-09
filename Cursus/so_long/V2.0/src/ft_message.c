/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_message.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 09:49:06 by fbouchar          #+#    #+#             */
/*   Updated: 2023/03/06 15:22:54 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print_moves_and_collect(t_map *ms)
{
	mlx_delete_image(ms->mlx, ms->image.move);
	ms->image.move = mlx_put_string(ms->mlx, "Moves:", 3,
			ms->row * 64 + 5);
	ms->image.hay = mlx_put_string(ms->mlx, "Parcel of hay left:", 3,
			ms->row * 64 + 25);
}

void	ft_print_moves(t_map *ms)
{
	char	*move_count;

	move_count = ft_itoa(ms->move_count);
	mlx_delete_image(ms->mlx, ms->image.move_nbr);
	ms->image.move_nbr = mlx_put_string(ms->mlx,
			move_count, 70, ms->row * IS + 5);
	free(move_count);
}

void	ft_print_collected_c(t_map *ms)
{
	char	*collected_c;

	collected_c = ft_itoa(ms->c);
	mlx_delete_image(ms->mlx, ms->image.collected_nbr);
	ms->image.collected_nbr = mlx_put_string(ms->mlx,
			collected_c, 202, ms->row * IS + 25);
	if (ms->c == 0)
	{
		ms->image.collected_nbr = mlx_put_string(ms->mlx,
				" to collect...You can go home now!", 212, ms->row * IS + 25);
	}
	free(collected_c);
}
