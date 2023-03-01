/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 13:58:24 by fbouchar          #+#    #+#             */
/*   Updated: 2023/03/01 15:11:30 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

mlx_image_t	*ft_load_image(char c, t_map *ms)
{
	if (c == '1')
		return (ms->image.wall);
	if (c == '0')
		return (ms->image.floor);
	if (c == 'P')
	{
		if (ms->direction == 'N')
			return (ms->image.playern);
		if (ms->direction == 'S')
			return (ms->image.players);
		if (ms->direction == 'E')
			return (ms->image.playere);
		if (ms->direction == 'O')
			return (ms->image.playero);
	}
	if (c == 'E')
		return (ms->image.exit);
	if (c == 'C')
		return (ms->image.collect);
	return (0);
}

void	ft_create_image(t_map *ms)
{
	ms->image.wall = mlx_texture_to_image(ms->mlx, ms->texture.wall);
	ms->image.floor = mlx_texture_to_image(ms->mlx, ms->texture.floor);
	ms->image.playern = mlx_texture_to_image(ms->mlx, ms->texture.playern);
	ms->image.players = mlx_texture_to_image(ms->mlx, ms->texture.players);
	ms->image.playere = mlx_texture_to_image(ms->mlx, ms->texture.playere);
	ms->image.playero = mlx_texture_to_image(ms->mlx, ms->texture.playero);
	ms->image.exit = mlx_texture_to_image(ms->mlx, ms->texture.exit);
	ms->image.collect = mlx_texture_to_image(ms->mlx, ms->texture.collect);
}

void	ft_delete_image(t_map *ms)
{
	mlx_delete_image(ms->mlx, ms->image.wall);
	mlx_delete_image(ms->mlx, ms->image.floor);
	mlx_delete_image(ms->mlx, ms->image.playern);
	mlx_delete_image(ms->mlx, ms->image.players);
	mlx_delete_image(ms->mlx, ms->image.playere);
	mlx_delete_image(ms->mlx, ms->image.playero);
	mlx_delete_image(ms->mlx, ms->image.exit);
	mlx_delete_image(ms->mlx, ms->image.collect);
}
