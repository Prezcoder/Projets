/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 08:38:49 by fbouchar          #+#    #+#             */
/*   Updated: 2023/02/22 13:50:32 by fbouchar         ###   ########.fr       */
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

t_map	*count_objects(char *file, t_map *ms)
{
	int		i;

	i = 0;
	while (file[i])
	{
		if (file[i] == 'P')
			ms->p++;
		else if (file[i] == 'E')
			ms->e++;
		else if (file[i] == 'C')
			ms->c++;
		else if (file[i] == '\n')
			ms->row++;
		i++;
	}
	ms->all_char = i;
	ms->column = ft_column(file);
	ms->row += 1;
	ms->rectangle = map_is_rec(ms);
	ms->wall = ft_wall(file);
	return (ms);
}

t_map	*ft_parsing(int fd)
{
	char	*file;
	t_map	*ms;

	ms = get_ms();
	file = ft_read_map(fd);
	count_objects(file, ms);
	ft_validate(ms);
	ms->map = ft_split(file, '\n');
	free(file);
	return (ms);
}
