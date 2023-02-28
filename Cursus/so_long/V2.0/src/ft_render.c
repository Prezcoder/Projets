/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:34:18 by fbouchar          #+#    #+#             */
/*   Updated: 2023/02/28 13:43:39 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_texture(t_map *ms)
{
	mlx_delete_texture(ms->texture.wall);
	mlx_delete_texture(ms->texture.floor);
	mlx_delete_texture(ms->texture.player);
	mlx_delete_texture(ms->texture.exit);
	mlx_delete_texture(ms->texture.collect);
}

void	ft_load_texture(t_map *ms)
{
	ms->texture.wall = mlx_load_png(WALL);
	ms->texture.floor = mlx_load_png(FLOOR);
	ms->texture.player = mlx_load_png(PLAYER);
	ms->texture.exit = mlx_load_png(EXIT);
	ms->texture.collect = mlx_load_png(COLLECT);
}

mlx_texture_t	*ft_load_image(char c, t_map *ms)
{
	if (c == '1')
		return (ms->texture.wall);
	if (c == '0')
		return (ms->texture.floor);
	if (c == 'P')
		return (ms->texture.player);
	if (c == 'E')
		return (ms->texture.exit);
	if (c == 'C')
		return (ms->texture.collect);
	return (0);
}

void	ft_make_map(t_map *ms)
{
	int	x;
	int	y;

	y = 0;
	while (y < ms->row)
	{
		x = 0;
		while (x < ms->column)
		{
			ms->img = mlx_texture_to_image(ms->mlx, ft_load_image(ms->map[y][x], ms));
			mlx_image_to_window(ms->mlx, ms->img, (x * IS), (y * IS));
			x++;
		}
		y++;
	}
}

void	ft_render(t_map *ms)
{
	ms->mlx = mlx_init(ms->column * IS, ms->row * IS, "so_long", false);
	ft_load_texture(ms);
	ft_make_map(ms);
	mlx_loop(ms->mlx);
	ft_free_texture(ms);
	mlx_terminate(ms->mlx);
}
