/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:53:48 by fbouchar          #+#    #+#             */
/*   Updated: 2023/02/28 15:28:10 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define IS 64

# define WALL "./images/bricksx64.png"
# define FLOOR "./images/Drain_Cover_64.png"
# define PLAYER "./images/zorn1_64.png"
# define COLLECT "./images/alan1_64.png"
# define EXIT "./images/Floor_Glass_64x64.png"

# include "../libft/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "../MLX42/include/MLX42/MLX42.h"

typedef struct s_player
{
	int	x;
	int	y;
}	t_player;

typedef struct s_flood
{
	char	**map;
	int		collect;
	int		exit;
}	t_flood;

typedef struct s_texture
{
	mlx_texture_t	*wall;
	mlx_texture_t	*floor;
	mlx_texture_t	*player;
	mlx_texture_t	*exit;
	mlx_texture_t	*collect;
}	t_texture;

typedef struct s_map
{
	int			column;
	int			row;
	int			p;
	int			c;
	int			e;
	int			rectangle;
	int			wrong_char;
	int			wall;
	int			valid;
	char		**map;
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_flood		flood;
	t_player	player;
	t_texture	texture;

}	t_map;

void		get_ms(t_map *ms);
void		ft_read_map(char *path, t_map *ms);
void		count_objects(t_map *ms);
void		free_ms(t_map *ms);
void		map_is_rec(t_map *ms);
int			ft_column(char *file);
void		ft_wall(t_map *ms);
int			ft_validate(t_map *ms);
void		ft_parsing(char *path, t_map *ms);
t_map		*map_lines(char *path, t_map *ms);
void		ft_flood(t_map *ms);
void		ft_flood_cpy(t_map *ms);
void		flood_fill(int y, int x, t_map *ms);
void		ft_count(t_map *ms, int x, int y);
void		ft_render(t_map *ms);
void		ft_load_texture(t_map *ms);
void		ft_free_texture(t_map *ms);
void		ft_make_map(t_map *ms);
void		ft_key_hook(t_map *ms);

#endif