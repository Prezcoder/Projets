/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:53:48 by fbouchar          #+#    #+#             */
/*   Updated: 2023/03/09 08:40:42 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define IS 64

# define WALL "./images/Mur1.png"
# define FLOOR "./images/Sol2.png"
# define FLOOR2 "./images/Sol1.png"
# define PLAYERN "./images/Joueur1.png"
# define PLAYERS "./images/Joueur3.png"
# define PLAYERE "./images/Joueur2.png"
# define PLAYERO "./images/Joueur4.png"
# define COLLECT "./images/Foin1.png"
# define EXIT "./images/Exit1.png"
# define EXIT2 "./images/Exit2.png"
# define VACHE1 "./images/Vache1.png"
# define VACHE2 "./images/Vache2.png"
# define VACHE3 "./images/Vache3.png"
# define VACHE4 "./images/Vache4.png"

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
	int	xx;
	int	xy;
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
	mlx_texture_t	*floor2;
	mlx_texture_t	*playern;
	mlx_texture_t	*players;
	mlx_texture_t	*playere;
	mlx_texture_t	*playero;
	mlx_texture_t	*cow[5];
	mlx_texture_t	*exit;
	mlx_texture_t	*exit2;
	mlx_texture_t	*collect;
}	t_texture;

typedef struct s_image
{
	mlx_image_t	*wall;
	mlx_image_t	*floor;
	mlx_image_t	*floor2;
	mlx_image_t	*playern;
	mlx_image_t	*players;
	mlx_image_t	*playere;
	mlx_image_t	*playero;
	mlx_image_t	*cow;
	mlx_image_t	*exit;
	mlx_image_t	*exit2;
	mlx_image_t	*collect;
	mlx_image_t	*move_nbr;
	mlx_image_t	*collected_nbr;
	mlx_image_t	*move;
	mlx_image_t	*hay;
}	t_image;

typedef struct s_map
{
	int			column;
	int			row;
	int			p;
	int			x;
	int			c;
	int			e;
	int			vi;
	int			cowcount;
	int			rectangle;
	int			wrong_char;
	int			wall;
	int			valid;
	char		**map;
	int			move_count;
	char		direction;
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_flood		flood;
	t_player	player;
	t_texture	texture;
	t_image		image;
	t_image		old_image;
}	t_map;

void		get_ms(t_map *ms);
void		ft_read_map(char *path, t_map *ms);
void		count_objects(t_map *ms);
void		free_ms(t_map *ms);
void		map_is_rec(t_map *ms);
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
void		ft_make_map(void *param);
void		ft_key_hook(mlx_key_data_t keydata, void *param);
void		ft_up(t_map *ms);
void		ft_down(t_map *ms);
void		ft_right(t_map *ms);
void		ft_left(t_map *ms);
int			ft_check_for_c_and_e(t_map *ms, char c);
void		ft_delete_image_old(t_map *ms);
void		ft_create_image(t_map *ms);
mlx_image_t	*ft_load_image(char c, t_map *ms);
void		ft_print_moves(t_map *ms);
void		ft_print_collected_c(t_map *ms);
void		ft_print_moves_and_collect(t_map *ms);

#endif