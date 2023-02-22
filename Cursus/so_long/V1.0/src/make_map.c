/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 10:13:56 by fbouchar          #+#    #+#             */
/*   Updated: 2023/02/22 12:49:51 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_texture	*get_texture(void)
{
	static t_texture	*texture;

	if (!texture)
	{
		texture = malloc(sizeof(texture));
		if (!texture)
			return (NULL);
		texture->wall = 0;
		texture->floor = 0;
		texture->player = 0;
		texture->exit = 0;
		texture->collect = 0;
	}
	return (texture);
}
t_texture	*image_init(mlx_t *mlx)
{
	t_texture	*texture;
	mlx_texture_t *png;

	png = malloc(sizeof(png));
		if (!png)
			return (NULL);
	texture = get_texture();
	png = mlx_load_png(WALL);
	texture->wall = mlx_texture_to_image(mlx, png);
	png = mlx_load_png(FLOOR);
	texture->floor = mlx_texture_to_image(mlx, png);
	png = mlx_load_png(PLAYER);
	texture->player = mlx_texture_to_image(mlx, png);
	png = mlx_load_png(EXIT);
	texture->exit = mlx_texture_to_image(mlx, png);
	png = mlx_load_png(COLLECT);
	texture->collect = mlx_texture_to_image(mlx, png);
	mlx_delete_texture(png);
	return (texture);
}

void	ft_render(t_texture *texture, mlx_t *mlx, t_map *ms)
{
	int	x;
	int	y;

	y = 0;
	while (y < ms->row)
	{
		x = 0;
		while (x < ms->column)
		{
			if (ms->map[y][x] == '1')
				mlx_image_to_window(mlx, texture->wall, (x * IS), (y * IS));
			else if (ms->map[y][x] == '0')
				mlx_image_to_window(mlx, texture->floor, (x * IS), (y * IS));
			else if (ms->map[y][x] == 'E')
				mlx_image_to_window(mlx, texture->exit, (x * IS), (y * IS));
			else if (ms->map[y][x] == 'C')
				mlx_image_to_window(mlx, texture->collect, (x * IS), (y * IS));
			else if (ms->map[y][x] == 'P')
				mlx_image_to_window(mlx, texture->player, (x * IS), (y * IS));
			x++;
		}
		y++;
	}
}
