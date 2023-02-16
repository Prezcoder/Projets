/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 10:47:50 by fbouchar          #+#    #+#             */
/*   Updated: 2023/02/16 14:28:00 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_ms(t_map *ms)
{
	free(ms);
}

t_map	*get_ms(void)
{
	static t_map	*ms;

	if (!ms)
	{
		ms = malloc(sizeof(ms));
		ms->column = 0;
		ms->row = 0;
		ms->p = 0;
		ms->c = 0;
		ms->e = 0;
		ms->rectangle = 0;
		ms->all_char = 0;
	}
	return (ms);
}

int	main(void)
{
	char	*file;
	int		fd;
	t_map	*ms;

	fd = open("./map/map.ber", O_RDONLY);
	if (fd == -1)
		return (1);
	file = ft_read_map(fd);
	ms = count_objects(file);
	ft_printf("Personnage :%d\n", ms->p);
	ft_printf("Collectibles :%d\n", ms->c);
	ft_printf("Sortie :%d\n", ms->e);
	ft_printf("Lignes :%d\n", ms->row);
	ft_printf("Colones :%d\n", ms->column);
	ft_printf("Rectangle :%d\n", ms->rectangle);
	ft_printf("Longueur :%d\n", ms->all_char);
	ft_printf("Wall :%d\n", ft_wall(ms, file));
	close(fd);
	free_ms(ms);
}
