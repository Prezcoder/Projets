/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:52:45 by fbouchar          #+#    #+#             */
/*   Updated: 2023/02/22 13:51:21 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_read_map(int fd)
{
	char	*res;
	int		byte_read;
	char	*map_str;

	map_str = ft_calloc(1, 1);
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
