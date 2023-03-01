/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:34:18 by fbouchar          #+#    #+#             */
/*   Updated: 2023/03/01 15:08:07 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_texture(t_map *ms)
{
	mlx_delete_texture(ms->texture.wall);
	mlx_delete_texture(ms->texture.floor);
	mlx_delete_texture(ms->texture.playern);
	mlx_delete_texture(ms->texture.players);
	mlx_delete_texture(ms->texture.playere);
	mlx_delete_texture(ms->texture.playero);
	mlx_delete_texture(ms->texture.exit);
	mlx_delete_texture(ms->texture.collect);
}

void	ft_load_texture(t_map *ms)
{
	ms->texture.wall = mlx_load_png(WALL);
	ms->texture.floor = mlx_load_png(FLOOR);
	ms->texture.playern = mlx_load_png(PLAYERN);
	ms->texture.players = mlx_load_png(PLAYERS);
	ms->texture.playere = mlx_load_png(PLAYERE);
	ms->texture.playero = mlx_load_png(PLAYERO);
	ms->texture.exit = mlx_load_png(EXIT);
	ms->texture.collect = mlx_load_png(COLLECT);
}

void	ft_make_map(void *param)	
{
	int		x;
	int		y;
	t_map	*ms;

	ms = param;
	y = 0;
	ft_delete_image(ms);
	ft_create_image(ms);
	while (y < ms->row)
	{
		x = 0;
		while (x < ms->column)
		{
			ms->img = ft_load_image(ms->map[y][x], ms);
			mlx_image_to_window(ms->mlx, ms->img, (x * IS), (y * IS));
			x++;
		}
		y++;
	}
}

void	ft_render(t_map *ms)
{
	ms->mlx = mlx_init(ms->column * IS, ms->row * IS, "so_long", false);
	if (!ms->mlx)
		exit(EXIT_FAILURE);
	ft_load_texture(ms);
	ft_make_map(ms);
	// mlx_loop_hook(ms->mlx, &ft_make_map, ms);
	mlx_key_hook(ms->mlx, &ft_key_hook, ms);
	mlx_loop(ms->mlx);
	ft_free_texture(ms);
}
