/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:22:47 by fbouchar          #+#    #+#             */
/*   Updated: 2023/05/03 11:18:55 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_init_data(t_data *data)
{	
	data->arg = NULL;
	data->a = NULL;
	data->b = NULL;
	data->flag = 0;
	data->count = 0;
	data->mid = 0;
	data->min = 0;
	data->max = 0;
	data->range = 0;
	data->done = 0;
	data->spot = 0;
	data->last = 0;
	data->low_a = INT_MAX;
	data->high_a = INT_MIN;
	data->high_b = INT_MIN;
}

void	ft_make_choice(t_data *data)
{
	if (data->count == 2)
		ft_stack_swap(data, 'a');
	else if (data->count == 3)
		ft_three(data);
	else if (data->count == 4)
		ft_four(data);
	else if (data->count == 5)
		ft_five(data);
	else if (data->count > 5)
	{
		if (data->count % 2 == 0)
		{	
			ft_sort(data, 6);
			ft_sort(data, 3);
			ft_sort(data, 2);
		}
		else if (data->count % 2 != 0)
		{	
			ft_sort(data, 4);
			ft_sort(data, 2);
			ft_push_b(data);
		}
	}
}

void	ft_make_split(char *arg, t_data *data)
{
	data->arg = ft_split(arg, ' ');
	data->flag = 1;
	ft_check_number(data, 0);
	ft_check_doubles(data, 0);
	ft_make_list(data, 0);
	ft_count_n_found(data);
	ft_indexation(data);
	ft_checksort(data, 1);
	ft_make_choice(data);
	ft_merge(data);
	ft_error_n_out(data, 1);
}

void	ft_make_arg(t_data *data)
{
	ft_check_number(data, 1);
	ft_check_doubles(data, 1);
	ft_make_list(data, 1);
	ft_count_n_found(data);
	ft_indexation(data);
	ft_checksort(data, 1);
	ft_make_choice(data);
	ft_merge(data);
	ft_error_n_out(data, 1);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = malloc(sizeof(*data));
	if (!data)
		exit(EXIT_FAILURE);
	ft_init_data(data);
	if (argc == 2)
		ft_make_split(argv[1], data);
	else if (argc > 2)
	{
		data->arg = argv;
		ft_make_arg(data);
	}
	else if (argc < 2)
		ft_error_n_out(data, 1);
	return (0);
}
