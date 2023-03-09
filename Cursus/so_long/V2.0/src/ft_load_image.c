/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 13:58:24 by fbouchar          #+#    #+#             */
/*   Updated: 2023/03/06 15:30:32 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

mlx_image_t	*load_player(t_map *ms)
{
	if (ms->direction == 'N')
		return (ms->image.playern);
	if (ms->direction == 'S')
		return (ms->image.players);
	if (ms->direction == 'E')
		return (ms->image.playere);
	if (ms->direction == 'O')
		return (ms->image.playero);
	return (0);
}

mlx_image_t	*ft_load_image(char c, t_map *ms)
{
	if (c == '1')
		return (ms->image.wall);
	if (c == '0')
		return (ms->image.floor2);
	if (c == '2')
		return (ms->image.floor);
	if (c == 'P')
		return (load_player(ms));
	if (c == 'E')
	{
		if (ms->c == 0)
			return (ms->image.exit2);
		else if (ms->c != 0)
			return (ms->image.exit);
	}
	if (c == 'C')
		return (ms->image.collect);
	if (c == 'X')
		return (ms->image.cow);
	return (0);
}

void	ft_create_image(t_map *ms)
{
	ms->image.wall = mlx_texture_to_image(ms->mlx, ms->texture.wall);
	ms->image.floor = mlx_texture_to_image(ms->mlx, ms->texture.floor);
	ms->image.floor2 = mlx_texture_to_image(ms->mlx, ms->texture.floor2);
	ms->image.playern = mlx_texture_to_image(ms->mlx, ms->texture.playern);
	ms->image.players = mlx_texture_to_image(ms->mlx, ms->texture.players);
	ms->image.playere = mlx_texture_to_image(ms->mlx, ms->texture.playere);
	ms->image.playero = mlx_texture_to_image(ms->mlx, ms->texture.playero);
	ms->image.exit = mlx_texture_to_image(ms->mlx, ms->texture.exit);
	ms->image.exit2 = mlx_texture_to_image(ms->mlx, ms->texture.exit2);
	ms->image.collect = mlx_texture_to_image(ms->mlx, ms->texture.collect);
	if (ms->vi == 4)
		ms->vi = 0;
	ms->image.cow = mlx_texture_to_image(ms->mlx, ms->texture.cow[ms->vi]);
	if (ms->cowcount == 15)
		ms->image.cow = mlx_texture_to_image(ms->mlx, ms->texture.cow[ms->vi]);
	else if (ms->cowcount == 30)
		ms->image.cow = mlx_texture_to_image(ms->mlx, ms->texture.cow[ms->vi]);
	else if (ms->cowcount == 45)
	{
		ms->image.cow = mlx_texture_to_image(ms->mlx, ms->texture.cow[ms->vi]);
		ms->vi++;
		ms->cowcount = 0;
	}
	ms->cowcount++;
}

void	ft_delete_image_old(t_map *ms)
{
	mlx_delete_image(ms->mlx, ms->old_image.wall);
	mlx_delete_image(ms->mlx, ms->old_image.floor);
	mlx_delete_image(ms->mlx, ms->old_image.floor2);
	mlx_delete_image(ms->mlx, ms->old_image.playern);
	mlx_delete_image(ms->mlx, ms->old_image.players);
	mlx_delete_image(ms->mlx, ms->old_image.playere);
	mlx_delete_image(ms->mlx, ms->old_image.playero);
	mlx_delete_image(ms->mlx, ms->old_image.exit);
	mlx_delete_image(ms->mlx, ms->old_image.exit2);
	mlx_delete_image(ms->mlx, ms->old_image.collect);
	mlx_delete_image(ms->mlx, ms->old_image.hay);
	mlx_delete_image(ms->mlx, ms->old_image.cow);
}
