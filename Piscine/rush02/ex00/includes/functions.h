/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 17:34:08 by francoma          #+#    #+#             */
/*   Updated: 2022/12/11 16:58:01 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# define DICT_SIZE 32

typedef struct s_dict_entry
{
	unsigned int	key;
	char			*val;
}	t_dict_entry;
typedef unsigned int	t_uint;
int				is_space(char c);
int				ft_is_valid_dict_format(char *str);
int				ft_is_useful_entry(char *str, t_dict_entry	*dict);
int				ft_dict_is_complete(t_dict_entry	*dict);
long			ft_atoi(char *str);
char			*get_dict_str(char	*dict_p, int *dict_error);
int				ft_valid_unsigned_int(char *str);
int				is_space(char c);
int				ft_strlen(char *str);
void			ft_putstr(char *str);
int				ft_strcmp(char *s1, char *s2);
t_dict_entry	*ft_parse_dict(char *dict_str, int	*dict_error);
void			print_dict(t_dict_entry *dict);
t_dict_entry	find_dict_entry(t_uint nb, t_dict_entry *dict);
void			spell_number(long nb, t_dict_entry *dict);
void			spell_number_fr(long nb, t_dict_entry *dict);
void			free_dict(t_dict_entry	*dict, int nb_on_heap, char *nb_str);
int				ft_trim_space(char *dict_str);
char			*ft_read_std_entry(void);

#endif
