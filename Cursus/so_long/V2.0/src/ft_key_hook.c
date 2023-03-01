/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:26:54 by fbouchar          #+#    #+#             */
/*   Updated: 2023/03/01 14:07:01 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_key_hook(mlx_key_data_t keydata, void *param)
{
	t_map	*ms;

	ms = param;
	if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
	{
		if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP))
			ft_up(ms);
		if ((keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN))
			ft_down(ms);
		if ((keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT))
			ft_right(ms);
		if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT))
			ft_left(ms);
		if (keydata.key == MLX_KEY_ESCAPE)
		{
			ft_printf("%s", "Closing...\n");
			ft_printf("%s", "Have a good day!\n");
			mlx_close_window(ms->mlx);
		}	
		ft_make_map(ms);
	}
}
