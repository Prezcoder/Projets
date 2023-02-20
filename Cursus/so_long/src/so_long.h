/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:53:48 by fbouchar          #+#    #+#             */
/*   Updated: 2023/02/20 15:20:34 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#define WIDTH 2000
#define HEIGHT 2000

# include "../libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"

typedef struct s_map
{
	int	column;
	int	row;
	int	p;
	int	c;
	int	e;
	int	rectangle;
	int	all_char;
	int	wall;
}	t_map;

char		*ft_read_map(int fd);
t_map		*count_objects(char *file);
t_map		*get_ms(void);
void		free_ms(t_map *ms);
int			map_is_rec(t_map *ms);
int			ft_column(char *file);
int			ft_wall(t_map *ms, char *file);
int			ft_validate(t_map *ms);
int			ft_find_ber(char *name);

#endif