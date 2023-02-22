/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:53:48 by fbouchar          #+#    #+#             */
/*   Updated: 2023/02/22 15:21:41 by fbouchar         ###   ########.fr       */
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
// # include "../MLX42/include/MLX42/MLX42.h"

typedef struct s_map
{
	int			column;
	int			row;
	int			p;
	int			c;
	int			e;
	int			rectangle;
	int			all_char;
	int			wall;
	char		**map;
}	t_map;

t_map		*ft_read_map(char *map_path, t_map *ms);
t_map		*count_objects(t_map *ms);
t_map		*get_ms(void);
void		free_ms(t_map *ms);
int			map_is_rec(t_map *ms);
int			ft_column(char *file);
int  		ft_wall(char *file);
int			ft_validate(t_map *ms);
t_map		*ft_parsing(char *argv[1]);
int			map_lines(char *path);

#endif