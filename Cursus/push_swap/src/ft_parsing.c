/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 12:43:30 by fbouchar          #+#    #+#             */
/*   Updated: 2023/04/20 10:19:42 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void ft_count_n_found(t_data *data)
{
	t_stack	*temp;

	temp = NULL;
	temp = data->a;
	while (temp != NULL)
	{
		data->count++;
		if (data->low_a > temp->number)
			data->low_a = temp->number;
		if (data->high_a < temp->number)
			data->high_a = temp->number;
		temp = temp->next;
	}
	if (data->count == 1)
		ft_error_n_out(data, 1);
}

int	ft_checksort(t_data *data, int i)
{
	t_stack	*temp;

	temp = NULL;
	temp = data->a;
	while (temp->next != NULL)
	{	
		if (temp->number > temp->next->number)
			return (0);
		temp = temp->next;
	}
	if (i == 1)
		ft_error_n_out(data, 1);
	return (1);
}

int	ft_checksort_b(t_data *data, int i)
{
	t_stack	*temp;

	temp = NULL;
	temp = data->b;
	while (temp->next != NULL)
	{	
		if (temp->number > temp->next->number)
			return (0);
		temp = temp->next;
	}
	if (i == 1)
		ft_error_n_out(data, 1);
	return (1);
}

void	ft_error_n_out(t_data *data, int i)
{
	if (i == 0)
		ft_putendl_fd("Error", 2);
	if (data->a != NULL)
		ft_free_stack(data->a);
	if (data->a != NULL)
		ft_free_stack(data->b);
	if (data->flag == 1)
		ft_freeall(data->arg);
	free(data);
	exit(EXIT_FAILURE);
}

void	ft_check_doubles(t_data *data, int i)
{
	int			j;
	long int	nb1;
	long int	nb2;

	while (data->arg[i])
	{
		nb1 = ft_atoi(data->arg[i]);
		j = i + 1;
		while (data->arg[j])
		{
			nb2 = ft_atoi(data->arg[j]);
			if (nb1 == nb2)
				ft_error_n_out(data, 0);
			j++;
		}
		i++;
	}
}

void	ft_check_number(t_data *data, int i)
{
	int	j;

	j = 0;
	if (data->arg[i] == NULL)
		ft_error_n_out(data, 0);
	while (data->arg[i])
	{
		while (data->arg[i][j])
		{
			if ((!(data->arg[i][j] >= '0' && data->arg[i][j] <= '9')))
			{	
				if ((data->arg[i][j] == '-') && j == 0)
					j++;
				if (!(data->arg[i][j] >= '0' && data->arg[i][j] <= '9'))
					ft_error_n_out(data, 0);
			}
			j++;
		}
		j = 0;
		i++;
	}
}
