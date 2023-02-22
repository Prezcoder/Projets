/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 10:47:50 by fbouchar          #+#    #+#             */
/*   Updated: 2023/02/22 15:46:43 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_ms(t_map *ms)
{
	free(ms);
}

int	main(int argc, char **argv)
{
	int			fd;
	t_map		*ms;


	if (argc != 2)
		return (ft_printf("Invalid number of arguments.\n"));
	if (ft_strncmp(&argv[1][ft_strlen(argv[1]) - 4], ".ber", 4))
		return (ft_printf("Error\nThe file format isn't good.\n"));
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (ft_printf("Open failed.\n"));
	ft_printf("%d", map_lines(argv[1]));
	
	ms = ft_parsing(&argv[1]);
	ft_printf("%d", ms->p);
	close(fd);
	ft_freeall(ms->map);
	free_ms(ms);
	return (0);
}
