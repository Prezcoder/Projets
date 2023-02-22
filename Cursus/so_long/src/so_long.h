/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:53:48 by fbouchar          #+#    #+#             */
/*   Updated: 2023/02/21 13:30:01 by fbouchar         ###   ########.fr       */
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
# include "../MLX42/include/MLX42/MLX42.h"

typedef struct s_map
{
	int		column;
	int		row;
	int		p;
	int		c;
	int		e;
	int		rectangle;
	int		all_char;
	int		wall;
	char	**map;
}	t_map;

typedef struct s_texture
{
	mlx_image_t	*wall;
	mlx_image_t	*floor;
	mlx_image_t	*player;
	mlx_image_t	*exit;
	mlx_image_t	*collect;
}	t_texture;

char		*ft_read_map(int fd);
t_map		*count_objects(char *file);
t_map		*get_ms(void);
void		free_ms(t_map *ms);
int			map_is_rec(t_map *ms);
int			ft_column(char *file);
int			ft_wall(t_map *ms, char *file);
int			ft_validate(t_map *ms);
int			ft_find_ber(char *name);
t_texture	*image_init(mlx_t *mlx);
int			ft_render(t_texture *texture, mlx_t *mlx, t_map *ms);
t_map		*ft_parsing(int fd);

#endif