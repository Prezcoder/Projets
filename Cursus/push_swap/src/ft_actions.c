/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 12:13:44 by fbouchar          #+#    #+#             */
/*   Updated: 2023/04/26 12:55:26 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_indexation(t_data *data)
{
	int		i;
	int		nb;
	t_stack	*temp;

	temp = data->a;
	i = 1;
	nb = INT_MAX;
	while (i <= data->count)
	{
		while (temp != NULL)
		{
			if (nb > temp->number && temp->index == 0)
				nb = temp->number;
			temp = temp->next;
		}
		temp = data->a;
		while (temp->number != nb)
			temp = temp->next;
		temp->index = i;
		temp = data->a;
		nb = INT_MAX;
		i++;
	}
}

void	ft_stack_swap(t_data *data, char stack)
{
	if (stack == 'a')
	{
		data->a = ft_swap(data->a);
		ft_printf("sa\n");
	}
	if (stack == 'b')
	{
		data->b = ft_swap(data->b);
		ft_printf("sb\n");
	}
	if (stack == 's')
	{
		data->a = ft_swap(data->a);
		data->b = ft_swap(data->b);
		ft_printf("ss\n");
	}
}

void	ft_stack_rotate(t_data *data, char stack)
{
	if (stack == 'a')
	{
		data->a = ft_rotate(data->a);
		ft_printf("ra\n");
	}
	if (stack == 'b')
	{
		data->b = ft_rotate(data->b);
		ft_printf("rb\n");
	}
	if (stack == 'r')
	{
		data->a = ft_rotate(data->a);
		data->b = ft_rotate(data->b);
		ft_printf("rr\n");
	}
}

void	ft_stack_rrotate(t_data *data, char stack)
{
	if (stack == 'a')
	{
		data->a = ft_rrotate(data->a);
		ft_printf("rra\n");
	}
	if (stack == 'b')
	{
		data->b = ft_rrotate(data->b);
		ft_printf("rrb\n");
	}
	if (stack == 'r')
	{
		data->a = ft_rrotate(data->a);
		data->b = ft_rrotate(data->b);
		ft_printf("rrr\n");
	}
}
