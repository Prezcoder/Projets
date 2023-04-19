/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instruct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 13:22:33 by fbouchar          #+#    #+#             */
/*   Updated: 2023/04/18 12:48:33 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_push_a(t_data *data)
{
	t_stack	*temp;
	
	temp = NULL;
	if (!data->b)
		return;
	temp = data->b->next;
	data->b->next = data->a;
	data->a = data->b;
	data->b = temp;
}

void	ft_push_b(t_data *data)
{
	t_stack	*temp;
	
	temp = NULL;
	if (!data->a)
		return;
	temp = data->a->next;
	data->a->next = data->b;
	data->b = data->a;
	data->a = temp;
}

t_stack	*ft_rotate(t_stack *stack)
{
	t_stack *temp;
	
	temp = NULL;
	temp = stack;
	while (stack->next != NULL)
		stack = stack->next;
	stack->next = temp;
	stack = temp->next;
	temp->next = NULL;
	return (stack);
}

t_stack	*ft_rrotate(t_stack *stack)
{
	t_stack	*temp;
	
	temp = stack;
	while (stack->next->next != NULL)
		stack = stack->next;
	stack->next->next = temp;
	temp = stack->next;
	stack->next = NULL;
	stack = temp;
	return (stack);
}

t_stack	*ft_swap(t_stack *stack)
{
	t_stack *temp;

	temp = NULL;
	temp = stack->next;
	stack->next = stack->next->next;
	temp->next = stack;
	stack = temp;
	return (stack);
}
