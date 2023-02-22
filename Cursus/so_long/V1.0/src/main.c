/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 10:47:50 by fbouchar          #+#    #+#             */
/*   Updated: 2023/02/22 13:52:30 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_ms(t_map *ms)
{
	free(ms);
}

void	ft_free_texture(mlx_t *mlx, t_texture *texture)
{
	mlx_delete_image(mlx, texture->collect);
	mlx_delete_image(mlx, texture->floor);
	mlx_delete_image(mlx, texture->player);
	mlx_delete_image(mlx, texture->wall);
	mlx_delete_image(mlx, texture->exit);
}

int	main(int argc, char **argv)
{
	int			fd;
	t_map		*ms;
	mlx_t		*mlx;
	t_texture	*texture;

	if (argc != 2)
		return (ft_printf("Invalid number of arguments.\n"));
	if (ft_strncmp(&argv[1][ft_strlen(argv[1]) - 4], ".ber", 4))
		return (ft_printf("Error\nThe file format isn't good.\n"));
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (ft_printf("Open failed.\n"));
	ms = ft_parsing(fd);
	close(fd);
	mlx = mlx_init(ms->column * IS, ms->row * IS, "so_long", true);
	texture = image_init(mlx);
	ft_render(texture, mlx, ms);	
	ft_freeall(ms->map);
	mlx_loop(mlx);
	ft_free_texture(mlx, texture);
	mlx_terminate(mlx);
	free_ms(ms);
	return (0);
}
