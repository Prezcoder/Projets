/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 08:38:49 by fbouchar          #+#    #+#             */
/*   Updated: 2023/02/27 15:30:49 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_validate(t_map *ms)
{
	if (ms->p < 1)
		return (ft_printf("Error\nNo player detected."));
	if (ms->e != 1)
		return (ft_printf("Error\nNo exit or too many exits."));
	if (ms->c < 1)
		return (ft_printf("Error\nNo collectible detected."));
	if (ms->rectangle == 1)
		return (ft_printf("Error\nThe map isn't rectangular."));
	if (ms->wall == 1)
		return (ft_printf("Error\nThe map isn't framed by walls."));
	else
	{
		ms->valid = 0;
		return (ft_printf("The map...It's all good man!\n"));
	}
	return (0);
}

void	map_is_rec(t_map *ms)
{
	int y;

	y = 0;
	while (ms->map[y])
	{
		if (ft_strlen(ms->map[y]) == (size_t)ms->column)
			y++;
		else if (ft_strlen(ms->map[y]) != (size_t)ms->column)
			ms->rectangle = 1;
	}
	ms->rectangle = 0;
}

void	count_objects(t_map *ms)
{
	int		x;
	int 	y;

	y = 0;
	x = 0;
	while (ms->map[y])
	{
		x = 0;
		while (ms->map[y][x])
		{
			if (ms->map[y][x] == 'P')
				ms->p++;
			else if (ms->map[y][x] == 'E')
				ms->e++;
			else if (ms->map[y][x] == 'C')
				ms->c++;
			else if (ms->map[y][x] == '1' || ms->map[y][x] == '0')
				;
			else
				ms->wrong_char++;
			x++;
		}
		y++;
	}
	ms->column = ft_strlen(ms->map[0]);
	map_is_rec(ms);
	ft_wall(ms);
}

void	ft_read_map(char *path, t_map *ms)
{
	int y;
	int	fd;

	y = 0;
	map_lines(path, ms);
	ms->map = ft_calloc(sizeof(char *), (ms->row + 1));
	if (!ms->map)
		return;
	fd = open(path, O_RDONLY);
	while (1)
	{
		ms->map[y] = get_next_line(fd);
		if (ms->map[y] == NULL)
			break;
		if (ms->map[y][0] == '\n')
			ms->rectangle = 1;
		if (ms->map[y][ft_strlen(ms->map[y]) - 1] == '\n')
			ms->map[y][ft_strlen(ms->map[y]) - 1] = '\0';
		y++;
	}
	close (fd);
}

void	ft_parsing(char *path, t_map *ms)
{
	ft_read_map(path, ms);
	count_objects(ms);
	ft_validate(ms);
}

void	ft_flood_cpy(t_map *ms)
{
	int i;

	i = 0;
	ms->flood.map = ft_calloc(ms->column + 1, sizeof(char *));
	while (ms->map[i])
	{
		ms->flood.map[i] = ft_calloc(ms->column + 1, sizeof(char));
		ft_memcpy(ms->flood.map[i], ms->map[i], ms->column + 1);
		// ft_printf("%s\n", ms->flood.map[i]);
		i++;
	}
}