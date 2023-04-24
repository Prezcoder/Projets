/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:28:13 by fbouchar          #+#    #+#             */
/*   Updated: 2023/04/24 08:49:21 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../includes/libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_stack
{
	int				index;
	int				number;
	struct s_stack	*next;
}				t_stack;

typedef struct s_data
{
	char	**arg;
	int		flag;
	int		count;
	int		low_a;
	int		high_a;
	int		low_b;
	int		high_b;
	int		last;
	int		lastb;
	int		to_last;
	int		to_lastb;
	t_stack	*a;
	t_stack	*b;	
}				t_data;

void	ft_init_data(t_data *data);
void	ft_check_number(t_data *data, int i);
void	ft_check_doubles(t_data *data, int i);
void 	ft_count_n_found(t_data *data);
int		ft_checksort(t_data *data, int i);
int		ft_checksort_b(t_data *data, int i);
int		ft_semi_sort_a(t_data *data);
int		ft_semi_sort_b(t_data *data);
void	ft_error_n_out(t_data *data, int i);

t_stack	*ft_lstnew_int(int content);
t_stack	*ft_lstlast_int(t_stack *stack);
void	ft_iter_a(t_data *data);
void	ft_iter_b(t_data *data);
void	ft_make_list(t_data *data, int i);
void	ft_free_stack(t_stack *stack);

t_stack	*ft_swap(t_stack *stack);
void	ft_push_a(t_data *data);
void	ft_push_b(t_data *data);
t_stack	*ft_rotate(t_stack *stack);
t_stack	*ft_rrotate(t_stack *stack);
void	ft_stack_swap(t_data *data, char stack);
void	ft_stack_rotate(t_data *data, char stack);
void	ft_stack_rrotate(t_data *data, char stack);

void	ft_sort(t_data *data);
void	ft_sort_a(t_data *data);
void	ft_sort_b(t_data *data);
void	ft_sort_both(t_data *data);
void	ft_new_sort(t_data *data);

#endif