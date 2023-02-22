/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 08:38:49 by fbouchar          #+#    #+#             */
/*   Updated: 2023/02/22 15:51:07 by fbouchar         ###   ########.fr       */
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
		return (ft_printf("The map...It's all good man!"));
	return (0);
}

t_map	*get_ms(void)
{
	static t_map *ms;

	if (!ms)
	{
		ms = malloc(sizeof(t_map));
		ms->column = 0;
		ms->row = 0;
		ms->p = 0;
		ms->c = 0;
		ms->e = 0;
		ms->rectangle = 0;
		ms->all_char = 0;
		ms->wall = 0;
		ms->map = NULL;
	}
	return (ms);
}

t_map	*count_objects(t_map *ms)
{
	int		x;
	int 	y;

	y = 0;
	while (y != '\0')
	{
		x = 0;
		while (x != '\0')
		{
			if (ms->map[y][x] == 'P')
				ms->p++;
			else if (ms->map[y][x] == 'E')
				ms->e++;
			else if (ms->map[y][x] == 'C')
				ms->c++;
			else if (ms->map[y][x] == '\n')
				ms->row++;
			x++;
		}
		y++;
	}
	// ms->all_char = i;
	// ms->column = ft_column(file);
	// ms->row += 1;
	// ms->rectangle = map_is_rec(ms);
	// ms->wall = ft_wall(file);
	return (ms);
}

t_map	*ft_parsing(char *argv[1])
{
	t_map	*ms;

	ms = get_ms();
	ms = ft_read_map(argv[1], ms);
	count_objects(ms);
	// ft_validate(ms);
	return (ms);
}
