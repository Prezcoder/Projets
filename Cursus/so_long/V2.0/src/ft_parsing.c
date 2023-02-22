/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:52:45 by fbouchar          #+#    #+#             */
/*   Updated: 2023/02/22 15:56:23 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_lines(char *path)
{
	char	*str;
	int		fd;
	int		i;

	fd = open(path, O_RDONLY);
	i = 0;
	while (1)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break ;
		free(str);
		i++;
	}
	close(fd);
	return (i);
}

t_map	*ft_read_map(char *map_path, t_map *ms)
{
	int x;
	int y;
	int	fd;

	x = 0;
	y = 0;
	ms->map = (char **)malloc(sizeof(char *) * (map_lines(map_path) + 1));
	fd = open(map_path, O_RDONLY);
	while (1)
	{
		ms->map[y] = get_next_line(fd);
		if (ms->map[y] == NULL)
			break;
		y++;
	}
	if (!ms->map)
		return (0);
	ms->map[y + 1] = '\0';
	close (fd);
	ft_printf("%s", ms->map[2]);
	return (ms);
}

int	ft_column(char *file)
{
	int	i;

	i = 0;
	while (file[i] != '\n')
		i++;
	return (i);
}

int	map_is_rec(t_map *ms)
{
	if (((ms->all_char - ms->row + 1) % ms->column) == 0
		&& ((ms->all_char - ms->row + 1) % ms->row) == 0)
		return (0);
	else
		return (1);
}

int  ft_wall(char *file)
{
    int i;
    i = 0;
    while (file[i] != '\n')
    {
        if (file[i] != '1')
            return (1);
        i++;
    }
    while (file[i])
    {
        if (file[i] == '\n')
        {
            if (file[i + 1] != '1' || file[i - 1] != '1')
                return (1);
        }
        i++;
    }
    while (file[--i] != '\n')
    {
        if (file[i] != '1')
            return (1);
    }
    return (0);
}
