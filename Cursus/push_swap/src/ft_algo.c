/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 11:17:17 by fbouchar          #+#    #+#             */
/*   Updated: 2023/04/19 10:48:26 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_checksortstack(t_data *data)
{
	t_stack	*temp;

	temp = NULL;
	temp = data->a;
	while (temp)
	{
		while (temp->number < temp->next->number)
		{	
			temp = temp->next;
			if (temp->next == NULL)
				return (1);
		}
		break;
	}
	return (0);
}

void	ft_bubble_sort(t_data *data)
{
	while (1)
	{
		if (data->a->number > data->a->next->number && data->a->number == data->high)
			ft_stack_rotate(data, 'a');
		else if (data->a->number > data->a->next->number)
			ft_stack_swap(data, 'a');
		else
			ft_stack_rotate(data, 'a');
		ft_checksort(data);
		ft_sort(data);
	}
}

void	ft_sort(t_data *data)
{
	while (data->a)
	{
		ft_iter_list(data);
		ft_checksort(data);
		if (data->a->number > data->a->next->number && data->a->number == data->high)
		{	
			ft_stack_swap(data, 'a');
			ft_sort(data);
		}	
	
		if ((data->a->number < data->a->next->number) && (data->a->number > data->last))
		{	
			ft_stack_rrotate(data, 'a');
			ft_sort(data);
		}	
		if ((data->a->number < data->a->next->number) && (data->a->number < data->last))
		{
			ft_stack_rrotate(data, 'a');
			ft_sort(data);
		}
		if (data->a->number < data->a->next->number)
		{	
			ft_stack_rotate(data, 'a');
			ft_sort(data);
		}
		if (data->a->number > data->a->next->number)
		{	
			ft_stack_swap(data, 'a');
			if (data->a->next->next->number < data->a->next->number)
				ft_stack_rotate(data, 'a');
			ft_sort(data);
		}
		
	
		ft_checksort(data);
		ft_sort(data);
	}
}

