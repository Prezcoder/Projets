/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 11:17:17 by fbouchar          #+#    #+#             */
/*   Updated: 2023/05/02 09:19:04 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sort(t_data *data, int div)
{
	int 	i;
	int 	j;

	i = 0;
	j = 0;
	ft_iter_a(data, div);
	while (i < data->range && data->a != NULL)
	{
		if ((data->a->index >= data->min) && (data->a->index <= data->max))
		{
			ft_push_b(data);
			i++;
			j++;
			if (data->b->index < data->mid && data->b->next != NULL && data->b->index < data->b->next->index)
				ft_stack_rotate(data, 'b');
			if (j > 2)
			{
				if (data->b->index < data->b->next->index && data->b->index > data->mid)
					ft_stack_swap(data, 'b');
			}
		}
		else
			ft_stack_rotate(data, 'a');
	}
}

void	ft_merge(t_data *data, int div)
{
	t_stack *temp;
	int	nbr;
	int spot;
	int spothigh;
	int spothighsec;
	
	spothigh = 0;
	spothighsec = 0;
	spot = 0;
	temp = data->b;
	nbr = data->count / div;
	while (data->b != NULL)
	{
		spothigh = 0;
		data->high_b = INT_MIN;
		while (data->high_b != data->count)
		{
			spothigh++;
			if (data->high_b < temp->index)
				data->high_b = temp->index;
			temp = temp->next;
		}
		if (spothigh > data->count / 2)
		{
			spot = (spothigh - data->count);
			if (spot < 0)
				spot = (spot * -1) + 1;
			else
				spot += 1;
			while (spot != 0)
			{
				if (spot == 0)
				{
					ft_push_a(data);
					spot--;
				}
				while (spot > 0)
				{
					ft_stack_rrotate(data, 'b');
					spot--;
				}
				ft_push_a(data);
				temp = data->b;
			}
		}
		else 
		{			
			while (spothigh != 0)
			{
				if (spothigh == 1)
				{
					ft_push_a(data);
					spothigh--;
				}
				while (spothigh > 1)
				{
					ft_stack_rotate(data, 'b');
					spothigh--;
				}
				temp = data->b;
			}
		}
		data->count--;
		nbr--;
	}
	ft_push_a(data);
}

// void	ft_new_sort_a(t_data *data)
// {
// 	int	a;
// 	int	a_nxt;
// 	int	a_nnxt;
// 	int	a_hi;
// 	int a_lo;

// 	a = data->a->number;
// 	a_nxt = data->a->next->number;
// 	if (data->counta > 2)
// 		a_nnxt = data->a->next->next->number;
// 	a_hi = data->high_a;
// 	a_lo = data->low_a;

// 	ft_iter_a(data);
// 	if (ft_checksort(data, 0) == 1)
// 	{	
// 		ft_new_sort(data);
// 		exit(EXIT_SUCCESS);
// 	}
// 	if (a == a_hi && a_nxt != a_lo)
// 	{	
// 		ft_stack_swap(data, 'a');
// 		if (a_nnxt != a_lo)
// 			ft_stack_rotate(data, 'a');
// 		ft_new_sort_a(data);
// 	}
// 	if ((a == a_hi && a_nxt == a_lo) && (ft_semi_sort_a(data) == 1))
// 	{
// 		ft_stack_rotate(data, 'a');
// 		ft_new_sort_a(data);
// 	}	
// 	if (a > a_nxt && a != a_hi)
// 	{	
// 		ft_stack_swap(data, 'a');
// 		if (a > a_nnxt)
// 			ft_stack_rotate(data, 'a');
// 		ft_new_sort_a(data);
// 	}
// 	else
// 	{	
// 		ft_stack_rrotate(data, 'a');
// 		ft_new_sort_a(data);
// 	}
// }
