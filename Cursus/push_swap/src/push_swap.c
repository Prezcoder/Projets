/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:22:47 by fbouchar          #+#    #+#             */
/*   Updated: 2023/04/24 08:49:05 by fbouchar         ###   ########.fr       */
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
	data->last = 0;
	data->lastb = 0;
	data->to_last = 0;
	data->to_lastb = 0;
	data->low_a = INT_MAX;
	data->high_a = INT_MIN;
	data->low_b = INT_MAX;
	data->high_b = INT_MIN;
}

void	ft_make_split(char *arg, t_data *data)
{
	data->arg = ft_split(arg, ' ');
	data->flag = 1;
	ft_check_number(data, 0);
	ft_check_doubles(data, 0);
	ft_make_list(data, 0);
	ft_count_n_found(data);
	ft_checksort(data, 1);
	ft_new_sort(data);
}

void	ft_make_arg(t_data *data)
{
	ft_check_number(data, 1);
	ft_check_doubles(data, 1);
	ft_make_list(data, 1);
	ft_count_n_found(data);
	ft_checksort(data, 1);
	ft_new_sort(data);
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
	if (argc > 3)
	{
		data->arg = argv;
		ft_make_arg(data);
	}
	else if (argc < 2)
		ft_error_n_out(data, 0);
	// ft_iter_a(data);
	// ft_checksort(data);
	// ft_iter_listb(data);
}
