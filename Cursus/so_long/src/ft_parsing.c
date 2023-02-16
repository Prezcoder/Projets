/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:52:45 by fbouchar          #+#    #+#             */
/*   Updated: 2023/02/16 15:22:40 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_read_map(int fd)
{
	char	*res;
	int		byte_read;
	char	*map_str;

	map_str = malloc(1 * 1);
	res = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!res | !map_str)
		return (NULL);
	map_str[0] = '\0';
	byte_read = 1;
	while (byte_read != 0)
	{
		byte_read = read(fd, res, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(res);
			free(map_str);
			return (NULL);
		}
		res[byte_read] = '\0';
		map_str = ft_strjoin(map_str, res);
	}
	free(res);
	return (map_str);
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
		return (1);
	else
		return (0);
}

t_map	*count_objects(char *file)
{
	t_map	*ms;
	int		i;

	i = 0;
	ms = get_ms();
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
	ms->row++;
	ms->rectangle = map_is_rec(ms);
	free(file);
	return (ms);
}

int ft_wall(t_map *ms, char *file)
{
	ms->all_char--;
	while (file[ms->all_char] == '1')
		ms->all_char--;
	if (file[ms->all_char] != 1 && file[ms->all_char] != '\n')
			return (0);
	ms->all_char--;
	while (ms->all_char > ms->column)
	{
		if (file[ms->all_char] == '1')
			ms->all_char -= ms->column +1;
		else
			return (0);
	}
	while (file[ms->all_char] == '1')
		ms->all_char--;
	ms->all_char += ms->column + 2;
	while (file[ms->all_char])
	{
		if (file[ms->all_char] == '1')
			ms->all_char += ms->column + 1;
		else
			return (0);
	}
	return (1);
}
