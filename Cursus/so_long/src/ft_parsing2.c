/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 08:38:49 by fbouchar          #+#    #+#             */
/*   Updated: 2023/02/21 13:28:55 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_find_ber(char *name)
{
	int	i;
	int	j;

	i = ft_strlen(name) - 4;
	j = ft_strncmp(".ber", &name[i], 4);
	if (j == 0)
		return (0);
	else
		return (1);
}

int	ft_validate(t_map *ms)
{
	if (ms->p < 1)
		ft_printf("%s", "Error\nNo player detected.");
	else if (ms->e != 1)
		ft_printf("%s", "Error\nNo exit or too many exits.");
	else if (ms->c < 1)
		ft_printf("%s", "Error\nNo collectible detected.");
	else if (ms->rectangle == 1)
		ft_printf("%s", "Error\nThe map isn't rectangular.");
	else if (ms->wall == 1)
		ft_printf("%s", "Error\nThe map isn't framed by walls.");
	else
		ft_printf("%s", "The map...It's all good man!");
	return (1);
}

t_map	*ft_parsing(int fd)
{
	char	*file;
	t_map	*ms;

	ms = get_ms();
	file = ft_read_map(fd);
	ms = count_objects(file);
	ft_validate(ms);
	ms->map = ft_split(file, '\n');
	return (ms);
}
