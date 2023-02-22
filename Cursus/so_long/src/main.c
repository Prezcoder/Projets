/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 10:47:50 by fbouchar          #+#    #+#             */
/*   Updated: 2023/02/22 08:41:03 by fbouchar         ###   ########.fr       */
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
		ms->map = 0;
	}
	return (ms);
}

int	main(int argc, char **argv)
{
	int			fd;
	t_map		*ms;
	mlx_t		*mlx;

	if (argc != 2)
		return (ft_printf("%s", "Invalid number of arguments."));
	if (ft_find_ber(argv[1]) == 1)
		ft_printf("%s", "Error\nThe file format isn't good.\n");
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (ft_printf("%s", "Open failed.\n"));
	ms = ft_parsing(fd);
	close(fd);
	mlx = mlx_init(ms->column * IS, ms->row * IS, "so_long", 1);
	if (!mlx)
		return (ft_printf("%s", "mlx_init failed"));
	ft_render(image_init(mlx), mlx, ms);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	mlx_close_window(mlx);
	ft_freeall(ms->map);
	free_ms(ms);
}
