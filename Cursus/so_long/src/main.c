/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 10:47:50 by fbouchar          #+#    #+#             */
/*   Updated: 2023/02/20 15:58:27 by fbouchar         ###   ########.fr       */
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
		if (!ms)
			return (NULL);
		ms->column = 0;
		ms->row = 0;
		ms->p = 0;
		ms->c = 0;
		ms->e = 0;
		ms->rectangle = 0;
		ms->all_char = 0;
		ms->wall = 0;
	}
	return (ms);
}

int	main(int argc, char **argv)
{
	char		*file;
	int			fd;
	t_map		*ms;
	int			ber_ok;
	char		**map;
	mlx_t 		*mlx;
	mlx_image_t *img;

	if (argc != 2)
		return (ft_printf("%s", "Invalid number of arguments."));
	ber_ok = ft_find_ber(argv[1]);
	if (ber_ok == 1)
		ft_printf("%s", "Error\nThe file format isn't good.\n");
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (ft_printf("%s", "Open failed.\n"));
	file = ft_read_map(fd);
	ms = count_objects(file);
	ft_printf("Personnage :%d\n", ms->p);
	ft_printf("Collectibles :%d\n", ms->c);
	ft_printf("Sortie :%d\n", ms->e);
	ft_printf("Lignes :%d\n", ms->row);
	ft_printf("Colones :%d\n", ms->column);
	ft_printf("Rectangle :%d\n", ms->rectangle);
	ft_printf("Longueur :%d\n", ms->all_char);
	ft_printf("Wall :%d\n", ms->wall);
	ft_validate(ms);
	map = ft_split(file, '\n');
	close(fd);
	mlx = mlx_init(WIDTH, HEIGHT, "Test", 1);
	if (!mlx)
		return (ft_printf("%s", "mlx_init failed"));
	mlx_texture_t *texture = mlx_load_png("./images/bricksx64.png");
	img = mlx_texture_to_image(mlx, texture);
	int i = 0;
	int j = 0;

	while (map[i][j])
	{
		if (map[i][j] == '1')
			mlx_image_to_window(mlx, img, 0, (j * 64));
		j++;
	}
	
	
	mlx_loop(mlx);
	mlx_terminate(mlx);
	ft_freeall(map);
	free_ms(ms);
}
