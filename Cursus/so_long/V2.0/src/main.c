/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 10:47:50 by fbouchar          #+#    #+#             */
/*   Updated: 2023/03/09 12:48:07 by fbouchar         ###   ########.fr       */
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
	ms->x = 0;
	ms->c = 0;
	ms->e = 0;
	ms->rectangle = 0;
	ms->wrong_char = 0;
	ms->wall = 0;
	ms->valid = 0;
	ms->map = NULL;
	ms->move_count = 0;
	ms->flood.map = NULL;
	ms->flood.exit = 0;
	ms->flood.collect = 0;
	ms->player.x = 0;
	ms->player.y = 0;
	ms->player.xx = 0;
	ms->player.xy = 0;
	ms->vi = 0;
	ms->direction = 'N';
	ms->image.move_nbr = 0;
	ms->image.collected_nbr = 0;
	ms->image.move = 0;
	ms->cowcount = 0;
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
	ft_render(ms);
	mlx_terminate(ms->mlx);
	ft_freeall(ms->map);
	ft_printf("%s", "Closing...\n");
	ft_printf("%s", "Have a nice day and thanks for playing!\n");
	free_ms(ms);
	return (0);
}
