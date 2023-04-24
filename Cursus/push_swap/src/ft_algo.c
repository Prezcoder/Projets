/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 11:17:17 by fbouchar          #+#    #+#             */
/*   Updated: 2023/04/24 09:31:32 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_bubble_sort(t_data *data)
{
	while (1)
	{
		if (data->a->number > data->a->next->number && data->a->number == data->high_a)
			ft_stack_rotate(data, 'a');
		else if (data->a->number > data->a->next->number)
			ft_stack_swap(data, 'a');
		else
			ft_stack_rotate(data, 'a');
		ft_checksort(data, 1);
		ft_bubble_sort(data);
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

void	ft_sort(t_data *data)
{
	int i;

	i = 0;
	while (i < (data->count / 2))
	{
		ft_push_b(data);
		i++;
	}
	ft_sort_both(data);
	// ft_checksort(data);
}

void	ft_merge(t_data *data)
{	
	while (data->b != NULL)
	{	
		ft_iter_a(data);
		ft_iter_b(data);
		if ((data->a->number == data->low_a && data->b->number == data->high_b))
		{
			ft_push_a(data);
			ft_stack_rotate(data, 'a');
			ft_merge(data);
		}
		else if ((data->b->number > data->a->number) && (data->b->number != data->high_b))
		{	
			ft_stack_rotate(data, 'a');
			ft_push_a(data);
			ft_merge(data);
		}
		if (data->b->number < data->a->number)
		{	
			ft_push_a(data);
			ft_merge(data);
		}
	}
	if ((data->b == NULL) && (ft_checksort(data, 0) == 0))
	{	
		// ft_printf("Test:%i", ft_checksort(data, 0));
		ft_stack_rrotate(data, 'a');
		ft_merge(data);
	}
	if ((data->b == NULL) && (ft_checksort(data, 0) == 1))
		ft_error_n_out(data, 1);
	// else
	// {
	// 	// ft_printf("Test:%i", ft_checksort(data, 0));
	// 	ft_stack_rotate(data, 'a');
	// 	ft_merge(data);
	// }
}

void	ft_new_sort(t_data *data)
{
	int	a;
	// int	b;
	int	a_nxt;
	// int	b_nxt;
	int	a_hi;
	int a_lo;
	// int b_hi;
	// int	b_lo;

	a = data->a->number;
	// b = data->b->number;
	a_nxt = data->a->next->number;
	// b_nxt = data->b->next->number;
	a_hi = data->high_a;
	a_lo = data->low_a;
	// b_hi = data->high_b;
	// b_lo = data->low_b;

	ft_iter_a(data);
	if (ft_checksort(data, 0) == 1)
		// ft_merge(data);
		exit(EXIT_SUCCESS);
	if (a == a_hi && a_nxt != a_lo)
	{	
		ft_stack_swap(data, 'a');
		if (data->a->next->next->number != a_lo)
			ft_stack_rotate(data, 'a');
		ft_new_sort(data);
	}
	// if ((a == a_hi && a_nxt == a_lo) && (ft_semi_sort_a(data) == 0))
	// {
	// 	ft_stack_rotate(data, 'a');
	// 	ft_stack_rotate(data, 'a');
	// 	ft_new_sort(data);
	// }
	if ((a == a_hi && a_nxt == a_lo) && (ft_semi_sort_a(data) == 1))
	{
		ft_stack_rotate(data, 'a');
		ft_new_sort(data);
	}
	if (a > a_nxt && a != a_hi)
	{	
		ft_stack_swap(data, 'a');
		if (a > data->a->next->next->number)
			ft_stack_rotate(data, 'a');
		ft_new_sort(data);
	}
	else
	{	
		ft_stack_rrotate(data, 'a');
		ft_new_sort(data);
	}
}

void	ft_sort_both(t_data *data)
{
	ft_iter_a(data);
	ft_iter_b(data);
	if ((ft_checksort(data, 0) == 1) && (ft_checksort_b(data, 0) == 1))
	{
		ft_merge(data);
	}
	if ((ft_checksort(data, 0) == 1) && (ft_checksort_b(data, 0) == 0))
	{
		ft_sort_b(data);
	}
	if ((ft_checksort(data, 0) == 0) && (ft_checksort_b(data, 0) == 1))
	{
		ft_sort_a(data);
	}
	if ((data->a->number > data->a->next->number && data->a->number == data->high_a) && (data->b->number > data->b->next->number && data->b->number == data->high_b))
	{
		// ft_printf("A:%i", data->a->next->number);
		// ft_printf("B:%i", data->b->number);
		// ft_printf("B:%i", data->b->next->number);
		// ft_printf("B:%i", data->high_b);
		if (((ft_semi_sort_a(data) == 1) && (ft_semi_sort_b(data) == 1)))
			ft_stack_rotate(data, 'r');
		else if ((ft_semi_sort_a(data) == 1) && (ft_semi_sort_b(data) == 0))
			ft_stack_rotate(data, 'a');
		else if ((ft_semi_sort_a(data) == 0) && (ft_semi_sort_b(data) == 1))
			ft_stack_rotate(data, 'b');
		if ((data->a->number > data->a->next->number) && (data->b->number > data->b->next->number))
			ft_stack_swap(data, 's');
		else if ((data->a->number > data->a->next->number) && (data->b->number < data->b->next->number))
			ft_stack_swap(data, 'a');
		else if ((data->a->number < data->a->next->number) && (data->b->number > data->b->next->number))
			ft_stack_swap(data, 'b');
		ft_sort_both(data);
	}
	if (((data->a->number < data->a->next->number) && (data->a->number > data->last)) && ((data->b->number < data->b->next->number) && (data->b->number > data->lastb)))
	{
		ft_stack_rrotate(data, 'r');
		ft_sort_both(data);
	}
	if (((data->a->number < data->a->next->number) && (data->a->number < data->last)) && ((data->b->number < data->b->next->number) && (data->b->number < data->lastb)))
	{
		if ((data->last == data->low_a) && (data->lastb == data->low_b))
			ft_stack_rotate(data, 'r');
		else
			ft_stack_rrotate(data, 'r');
		ft_sort_both(data);
	}
	if ((data->a->number < data->a->next->number) && (data->b->number < data->b->next->number))
	{
		if (data->a->number > data->last && data->b->number < data->lastb)
			ft_stack_rrotate(data, 'r');
		else
			ft_stack_rotate(data, 'r');
		ft_sort_both(data);
	}
	if ((data->a->number > data->a->next->number) && (data->b->number > data->b->next->number))
	{
		ft_stack_swap(data, 's');
		if ((data->a->next->next->number < data->a->next->number) && (data->b->next->next->number < data->b->next->number))
			ft_stack_rotate(data, 'r');
		ft_sort_both(data);
	}
	if ((data->a->number > data->a->next->number) && (data->b->number < data->b->next->number))
	{
		ft_stack_swap(data, 'a');
		ft_stack_rotate(data, 'b');
		ft_sort_both(data);
	}
	if ((data->a->number < data->a->next->number) && (data->b->number > data->b->next->number))
	{
		ft_stack_swap(data, 'b');
		ft_stack_rrotate(data, 'a');
		ft_sort_both(data);
	}	
}

void	ft_sort_a(t_data *data)
{
		ft_iter_a(data);
		if (ft_checksort(data, 0) == 1)
			ft_sort_both(data);
		// ft_checksort(data, 1);
		if (data->a->number > data->a->next->number && data->a->number == data->high_a)
		{
			if (ft_semi_sort_a(data) == 1)
				ft_stack_rotate(data, 'a');
			else if (ft_semi_sort_a(data) == 0)
				ft_stack_swap(data, 'a');
			ft_sort_a(data);
		}
		if ((data->a->number < data->a->next->number) && (data->a->number > data->last))
		{
			ft_stack_rrotate(data, 'a');
			ft_sort_a(data);
		}
		if ((data->a->number < data->a->next->number) && (data->a->number < data->last))
		{
			if (data->last == data->low_a)
				ft_stack_rotate(data, 'a');
			else
				ft_stack_rrotate(data, 'a');
			ft_sort_a(data);
		}
		if (data->a->number < data->a->next->number)
		{
			ft_stack_rotate(data, 'a');
			ft_sort_a(data);
		}
		if (data->a->number > data->a->next->number)
		{
			ft_stack_swap(data, 'a');
			if (data->a->next->next->number < data->a->next->number)
				ft_stack_rotate(data, 'a');
			ft_sort_a(data);
		}
}

void	ft_sort_b(t_data *data)
{
		ft_iter_b(data);
		if (ft_checksort_b(data, 0) == 1)
			ft_sort_both(data);
		if (data->b->number > data->b->next->number && data->b->number == data->high_b)
		{
			if (ft_semi_sort_b(data) == 1)
				ft_stack_rotate(data, 'b');
			else if (ft_semi_sort_b(data) == 0)
				ft_stack_swap(data, 'b');
			ft_sort_b(data);
		}
		if ((data->b->number < data->b->next->number) && (data->b->number > data->lastb))
		{
			ft_stack_rrotate(data, 'b');
			ft_sort_b(data);
		}
		if ((data->b->number < data->b->next->number) && (data->b->number < data->lastb))
		{
			if (data->lastb == data->low_b)
				ft_stack_rotate(data, 'b');
			else
				ft_stack_rrotate(data, 'b');
			ft_sort_b(data);
		}
		if (data->b->number < data->b->next->number)
		{
			ft_stack_rotate(data, 'b');
			ft_sort_b(data);
		}
		if (data->b->number > data->b->next->number)
		{
			ft_stack_swap(data, 'b');
			if (data->b->next->next->number < data->b->next->number)
				ft_stack_rotate(data, 'b');
			ft_sort_b(data);
		}
}

