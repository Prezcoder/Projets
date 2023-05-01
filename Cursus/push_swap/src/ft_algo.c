/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 11:17:17 by fbouchar          #+#    #+#             */
/*   Updated: 2023/04/27 14:58:06 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sort_short(t_data *data)
{
	while (1)
	{
		if (data->a->number > data->a->next->number && data->a->number == data->high_a)
			ft_stack_rotate(data, 'a');
		else if (data->a->number > data->a->next->number)
			ft_stack_swap(data, 'a');
		else
			ft_stack_rotate(data, 'a');
		if (ft_semi_sort_a(data) == 1) 
			ft_stack_rotate(data, 'a');
		if (ft_checksort(data, 0) == 1)
			ft_merge(data);
		else
			ft_sort_short(data);
	}
}

int	ft_semi_sort_a(t_data *data)
{
	t_stack	*temp;

	temp = NULL;
	temp = data->a;
	temp = temp->next;
	while (temp->next != NULL)
	{	
		if (temp->number > temp->next->number)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	ft_semi_sort_b(t_data *data)
{
	t_stack	*temp;
	
	temp = NULL;
	temp = data->b;
	temp = temp->next;
	while (temp->next != NULL)
	{	
		if (temp->number > temp->next->number)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void	ft_sort_middle(t_data *data, int div)
{
	int 	i;
	int 	j;
	// t_stack	*temp;

	i = 0;
	j = 0;
	// temp = data->a;
	ft_iter_a(data, div);
	
	// return;
	if (data->a != NULL)
	{
		while (i < data->range && data->a != NULL)
		{
			// ft_printf("range :%i\n", data->range);
			// ft_printf("%i", i);
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
		// ft_sort(data);
	}
}

void	ft_find_next(t_data *data)
{
	int		i;
	t_stack	*temp;
	t_stack	*tempb;

	i = 0;
	temp = data->a;
	tempb = data->b;
	while (temp != NULL)
	{	
		if (tempb->index > temp->index)
			data->nxt = i;
		temp = temp->next;
		i++;
	}
	
}


void	ft_merge(t_data *data)
{	
	// ft_iter_a(data);
	if (data->a == NULL)
		ft_push_a(data);
	while (data->b != NULL)
	{	
		ft_count(data);
		ft_countb(data);
		if (data->countb > 1)
		{
			if (data->b->index < data->b->next->index)
				ft_stack_swap(data, 'b');	
		
		}
		if (data->countb > 0)
		{
			if (data->b->index < data->a->index)
			{
				ft_push_a(data);
				ft_check_last(data);
			}
		}
		
		if (data->counta > 1 && data->countb > 0)
		{	
			// ft_check_last(data);
			if (data->b->index > data->a->index && data->b->index < data->a->next->index)
			{
				ft_stack_rotate(data, 'a');
			}
			else if (data->b->index > data->a->index && data->b->index > data->a->next->index)
			{
				ft_find_next(data);
				// ft_printf("%i", data->nxt);
				if (data->nxt > 0)
				{
					while (data->nxt >= 0)
					{	
						ft_stack_rotate(data, 'a');
						data->nxt--;
					}
				}
				// else
				// 	ft_stack_rrotate(data, 'a');
			}
			// ft_check_last(data);
		}
		
	}
	if ((data->b == NULL) && (ft_checksort(data, 0) == 1))
	{	
		ft_error_n_out(data, 1);
		exit(EXIT_SUCCESS);
	}
	// if (data->b == NULL)
	// 	ft_error_n_out(data, 1);
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

// void	ft_new_sort_b(t_data *data)
// {
// 	int	b;
// 	int	b_nxt;
// 	int	b_nnxt;
// 	int	b_hi;
// 	int b_lo;

// 	b = data->b->number;
// 	b_nxt = data->b->next->number;
// 	if (data->countb > 2)
// 		b_nnxt = data->b->next->next->number;
// 	b_hi = data->high_b;
// 	b_lo = data->low_b;

// 	ft_iter_b(data);
// 	if (ft_checksort_b(data, 0) == 1)
// 	{	
// 		ft_new_sort(data);
// 		exit(EXIT_SUCCESS);
// 	}
// 	if (b == b_hi && b_nxt != b_lo)
// 	{	
// 		ft_stack_swap(data, 'b');
// 		if (b_nnxt != b_lo)
// 			ft_stack_rotate(data, 'b');
// 		ft_new_sort_b(data);
// 	}
// 	if ((b == b_hi && b_nxt == b_lo) && (ft_semi_sort_b(data) == 1))
// 	{
// 		ft_stack_rotate(data, 'b');
// 		ft_new_sort_b(data);
// 	}	
// 	if (b > b_nxt && b != b_hi)
// 	{	
// 		ft_stack_swap(data, 'b');
// 		if (b > b_nnxt)
// 			ft_stack_rotate(data, 'b');
// 		ft_new_sort_b(data);
// 	}
// 	else
// 	{	
// 		ft_stack_rrotate(data, 'b');
// 		ft_new_sort_b(data);
// 	}
// }
