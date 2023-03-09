/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:34:18 by fbouchar          #+#    #+#             */
/*   Updated: 2023/03/06 15:28:16 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_texture(t_map *ms)
{
	int	i;

	i = 0;
	mlx_delete_texture(ms->texture.wall);
	mlx_delete_texture(ms->texture.floor);
	mlx_delete_texture(ms->texture.floor2);
	mlx_delete_texture(ms->texture.playern);
	mlx_delete_texture(ms->texture.players);
	mlx_delete_texture(ms->texture.playere);
	mlx_delete_texture(ms->texture.playero);
	mlx_delete_texture(ms->texture.exit);
	mlx_delete_texture(ms->texture.exit2);
	mlx_delete_texture(ms->texture.collect);
	while (ms->texture.cow[i])
		mlx_delete_texture(ms->texture.cow[i++]);
}

void	ft_load_texture(t_map *ms)
{
	ms->texture.wall = mlx_load_png(WALL);
	ms->texture.floor = mlx_load_png(FLOOR);
	ms->texture.floor2 = mlx_load_png(FLOOR2);
	ms->texture.playern = mlx_load_png(PLAYERN);
	ms->texture.players = mlx_load_png(PLAYERS);
	ms->texture.playere = mlx_load_png(PLAYERE);
	ms->texture.playero = mlx_load_png(PLAYERO);
	ms->texture.exit = mlx_load_png(EXIT);
	ms->texture.exit2 = mlx_load_png(EXIT2);
	ms->texture.collect = mlx_load_png(COLLECT);
	ms->texture.cow[0] = mlx_load_png(VACHE1);
	ms->texture.cow[1] = mlx_load_png(VACHE2);
	ms->texture.cow[2] = mlx_load_png(VACHE3);
	ms->texture.cow[3] = mlx_load_png(VACHE4);
}

void	ft_make_map(void *param)
{
	int		x;
	int		y;
	t_map	*ms;

	ms = param;
	y = 0;
	ft_delete_image_old(ms);
	ms->old_image = ms->image;
	ft_create_image(ms);
	ft_print_moves_and_collect(ms);
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
	ms->mlx = mlx_init(ms->column * IS, ms->row * IS + 50, "so_long", false);
	if (!ms->mlx)
		exit(EXIT_FAILURE);
	ft_load_texture(ms);
	ft_make_map(ms);
	mlx_loop_hook(ms->mlx, &ft_make_map, ms);
	mlx_key_hook(ms->mlx, &ft_key_hook, ms);
	mlx_loop(ms->mlx);
	ft_free_texture(ms);
}
