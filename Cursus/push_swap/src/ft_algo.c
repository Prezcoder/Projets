/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 11:17:17 by fbouchar          #+#    #+#             */
/*   Updated: 2023/05/02 13:14:07 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sort(t_data *data, int div)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	ft_iter_a(data, div);
	while (i < data->range && data->a)
	{
		if ((data->a->index >= data->min) && (data->a->index <= data->max))
		{
			ft_push_b(data);
			i++;
			j++;
			if (data->b->index < data->mid && data->b->next
				&& data->b->index < data->b->next->index)
				ft_stack_rotate(data, 'b');
			if (j > 2 && data->b->index < data->b->next->index
				&& data->b->index > data->mid)
				ft_stack_swap(data, 'b');
		}
		else
			ft_stack_rotate(data, 'a');
	}
}

void	ft_find_high(t_data *data)
{
	t_stack	*temp;

	temp = data->b;
	data->spot = 0;
	data->high_b = INT_MIN;
	while (data->high_b != data->count)
	{
		data->spot++;
		if (data->high_b < temp->index)
			data->high_b = temp->index;
		temp = temp->next;
	}
}

void	ft_roll_down(t_data *data)
{
	while (data->spot != 0)
	{
		if (data->spot == 1)
		{
			ft_push_a(data);
			data->spot--;
			if (data->a->next && data->a->index > data->a->next->index)
				ft_stack_swap(data, 'a');
		}
		while (data->spot > 1)
		{
			if (data->b->next && data->b->index == data->high_b - 1)
			{	
				ft_push_a(data);
				data->count--;
			}
			else
				ft_stack_rotate(data, 'b');
			data->spot--;
		}
	}
}

void	ft_roll_up(t_data *data)
{
	while (data->spot != 0)
	{
		if (data->spot == 0)
		{
			ft_push_a(data);
			if (data->a->next && data->a->index > data->a->next->index)
				ft_stack_swap(data, 'a');
			data->spot--;
		}
		while (data->spot > 0)
		{
			ft_stack_rrotate(data, 'b');
			if (data->b->next && data->b->index == data->high_b - 1)
			{	
				ft_push_a(data);
				data->count--;
			}
			data->spot--;
		}
		ft_push_a(data);
		if (data->a->next && data->a->index > data->a->next->index)
			ft_stack_swap(data, 'a');
	}
}

void	ft_merge(t_data *data)
{
	while (data->b)
	{
		ft_find_high(data);
		if (data->spot > data->count / 2)
		{
			data->spot = (data->spot - data->count);
			if (data->spot < 0)
				data->spot = (data->spot * -1) + 1;
			else
				data->spot += 1;
			ft_roll_up(data);
		}
		else
			ft_roll_down(data);
		data->count--;
	}
	ft_push_a(data);
}
