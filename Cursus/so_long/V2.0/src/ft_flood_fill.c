/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flood_fill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 09:25:49 by fbouchar          #+#    #+#             */
/*   Updated: 2023/03/06 13:11:52 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_flood(t_map *ms)
{
	if (ms->valid == 0)
	{
		ft_flood_cpy(ms);
		flood_fill(ms->player.y, ms->player.x, ms);
		if (ms->c != ms->flood.collect)
			ft_printf("Error\nSome collectibles can't be reached.\n");
		if (ms->flood.exit != ms->e)
			ft_printf("Error\nThe exit can't be reached.\n");
	}
	ft_freeall(ms->flood.map);
}

void	ft_flood_cpy(t_map *ms)
{
	int	i;

	i = 0;
	ms->flood.map = ft_calloc(ms->row + 1, sizeof(char *));
	while (ms->map[i])
	{
		ms->flood.map[i] = ft_calloc(ms->column + 1, sizeof(char));
		ft_memcpy(ms->flood.map[i], ms->map[i], ms->column + 1);
		i++;
	}
}

void	flood_fill(int y, int x, t_map *ms)
{
	if (x < 0 || x > ms->column - 1 || y < 0 || y > ms->row - 1)
		return ;
	if (ms->flood.map[y][x] == 'Z' || ms->flood.map[y][x] == '1')
		return ;
	if (ms->flood.map[y][x] == 'C')
		ms->flood.collect++;
	if (ms->flood.map[y][x] == 'E')
		ms->flood.exit++;
	ms->flood.map[y][x] = 'Z';
	flood_fill(y + 1, x, ms);
	flood_fill(y - 1, x, ms);
	flood_fill(y, x - 1, ms);
	flood_fill(y, x + 1, ms);
}
