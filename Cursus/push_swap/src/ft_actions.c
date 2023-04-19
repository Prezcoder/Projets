/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 12:13:44 by fbouchar          #+#    #+#             */
/*   Updated: 2023/04/19 09:39:09 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
