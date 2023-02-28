/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 10:47:50 by fbouchar          #+#    #+#             */
/*   Updated: 2023/02/28 10:50:05 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_ms(t_map *ms)
{
	free(ms);
}

void	get_ms(t_map *ms)
{
	ms->column = 0;
	ms->row = 0;
	ms->p = 0;
	ms->c = 0;
	ms->e = 0;
	ms->rectangle = 0;
	ms->wrong_char = 0;
	ms->wall = 0;
	ms->valid = 0;
	ms->map = NULL;
	ms->flood.map = NULL;
	ms->flood.exit = 0;
	ms->flood.collect = 0;
	ms->player.x = 0;
	ms->player.y = 0;
}

int	main(int argc, char **argv)
{
	t_map		*ms;

	if (argc != 2)
		return (ft_printf("Invalid number of arguments.\n"));
	if (ft_strncmp(&argv[1][ft_strlen(argv[1]) - 4], ".ber", 4))
		return (ft_printf("Error\nThe file format isn't good.\n"));
	ms = malloc(sizeof(*ms));
	if (!ms)
		return (0);
	get_ms(ms);
	ft_parsing(argv[1], ms);
	ft_printf("Personnage :%d\n", ms->p);
	ft_printf("Exit :%d\n", ms->e);
	ft_printf("Collectibles :%d\n", ms->c);
	ft_printf("Wrong Char :%d\n", ms->wrong_char);
	ft_printf("Colonnes :%d\n", ms->column);
	ft_printf("Lignes :%d\n", ms->row);
	ft_printf("Rectangle :%d\n", ms->rectangle);
	ft_printf("Walled :%d\n", ms->wall);
	ft_printf("Flood collect :%d\n", ms->flood.collect);
	ft_printf("Flood exit :%d\n", ms->flood.exit);
	ft_freeall(ms->map);
	ft_freeall(ms->flood.map);
	free_ms(ms);
	return (0);
}
