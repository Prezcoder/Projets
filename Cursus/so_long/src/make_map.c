/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 10:13:56 by fbouchar          #+#    #+#             */
/*   Updated: 2023/02/21 15:05:27 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_texture	*image_init(mlx_t *mlx)
{
	static t_texture	*texture;

	if (!texture)
	{
		texture = malloc(sizeof(texture));
		if (!texture)
			return (NULL);
		texture->wall = mlx_texture_to_image(mlx, mlx_load_png(WALL));
		texture->floor = mlx_texture_to_image(mlx, mlx_load_png(FLOOR));
		texture->player = mlx_texture_to_image(mlx, mlx_load_png(PLAYER));
		texture->exit = mlx_texture_to_image(mlx, mlx_load_png(EXIT));
		texture->collect = mlx_texture_to_image(mlx, mlx_load_png(COLLECT));
	}
	return (texture);
}

int	ft_render(t_texture *texture, mlx_t *mlx, t_map *ms)
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
	return (0);
}
