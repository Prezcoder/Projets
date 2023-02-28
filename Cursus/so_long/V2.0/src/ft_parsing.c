/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:52:45 by fbouchar          #+#    #+#             */
/*   Updated: 2023/02/28 09:35:37 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	*map_lines(char *path, t_map *ms)
{
	char	*str;
	int		fd;

	fd = open(path, O_RDONLY);
	while (1)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break ;
		free(str);
		ms->row++;
	}
	close(fd);
	return (ms);
}

void	map_is_rec(t_map *ms)
{
	int	y;
	int	x;

	y = 0;
	while (ms->map[y])
	{
		x = 0;
		while (ms->map[y][x])
			x++;
		if (x != ms->column)
			ms->rectangle = 1;
		y++;
	}
}

void	ft_wall(t_map *ms)
{
	int	y;
	int	x;

	y = 0;
	while (ms->map[y])
	{
		x = 0;
		while (ms->map[y][x])
		{
			if (ms->map[0][x] != '1' || ms->map[y][0] != '1' ||
			ms->map[ms->row - 1][x] != '1' ||
			ms->map[y][ms->column - 1] != '1')
			ms->wall = 1;
			x++;
		}
		y++;
	}
}
