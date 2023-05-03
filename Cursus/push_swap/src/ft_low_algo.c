/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_low_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:31:52 by fbouchar          #+#    #+#             */
/*   Updated: 2023/05/02 15:43:42 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_counta(t_data *data)
{
	t_stack	*temp;
	int		i;

	i = 0;
	temp = NULL;
	temp = data->a;
	while (temp != NULL)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

void	ft_three(t_data *data)
{
	ft_iter_a(data, 1);
	if (ft_checksort(data, 0) == 1)
		return ;
	if (data->a->index > data->a->next->index && data->a->index < data->last)
		ft_stack_swap(data, 'a');
	else if (data->a->index > data->a->next->index
		&& data->a->index > data->last && data->a->next->index > data->last)
	{
		ft_stack_rotate(data, 'a');
		ft_stack_swap(data, 'a');
	}
	else if (data->a->index > data->a->next->index
		&& data->a->index > data->last && data->a->next->index < data->last)
		ft_stack_rotate(data, 'a');
	else if (data->a->index < data->a->next->index
		&& data->a->index > data->last)
		ft_stack_rrotate(data, 'a');
	else if (data->a->index < data->a->next->index
		&& data->a->index < data->last)
	{
		ft_stack_swap(data, 'a');
		ft_stack_rotate(data, 'a');
	}
}

void	ft_four(t_data *data)
{
	ft_iter_a(data, 1);
	while (data->a->index != data->low_a)
		ft_stack_rotate(data, 'a');
	if (data->a->index == data->low_a && ft_checksort(data, 0) == 0)
		ft_push_b(data);
	else if (ft_checksort(data, 0) == 1)
		return ;
	ft_three(data);
	if (data->b->next != NULL)
		ft_stack_swap(data, 'b');
	ft_push_a(data);
}

void	ft_five(t_data *data)
{
	ft_iter_a(data, 1);
	while (ft_counta(data) > 3)
	{
		if ((data->a->index == data->low_a)
			|| (data->a->index == data->high_a))
			ft_push_b(data);
		else
			ft_stack_rotate(data, 'a');
	}
	ft_three(data);
	ft_push_a(data);
	if (data->a->index > data->a->next->index)
	{
		ft_stack_rotate(data, 'a');
		ft_push_a(data);
	}
	else
	{
		ft_push_a(data);
		ft_stack_rotate(data, 'a');
	}
}
