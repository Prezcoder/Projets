/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 12:47:15 by fbouchar          #+#    #+#             */
/*   Updated: 2023/05/03 11:19:21 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_iter_a(t_data *data, int div)
{
	t_stack	*temp;

	data->low_a = INT_MAX;
	data->high_a = INT_MIN;
	temp = data->a;
	while (temp != NULL)
	{
		if (temp->index == data->count / 2)
			data->mid = temp->index;
		if (data->low_a > temp->index)
			data->low_a = temp->index;
		if (data->high_a < temp->index)
			data->high_a = temp->index;
		data->last = temp->index;
		temp = temp->next;
	}	
	data->min = data->mid - (data->count / div);
	data->max = data->mid + (data->count / div);
	data->done = data->range;
	data->range = data->max - data->min - data->done;
}

void	ft_free_stack(t_stack *stack)
{
	t_stack	*temp;

	while (stack)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
	}
	stack = NULL;
}

t_stack	*ft_lstlast_int(t_stack *stack)
{
	if (stack)
	{
		while (stack->next)
			stack = stack->next;
	}
	return (stack);
}

t_stack	*ft_lstnew_int(int content)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->number = content;
	stack->next = NULL;
	stack->index = 0;
	return (stack);
}

void	ft_make_list(t_data *data, int i)
{
	long int	nbr;
	t_stack		*temp;

	if (data->arg[i] == NULL)
	{
		ft_error_n_out(data, 1);
		exit(EXIT_FAILURE);
	}
	while (data->arg[i])
	{
		nbr = ft_atoi(data->arg[i]);
		if (data->a == NULL && (nbr >= INT_MIN && nbr <= INT_MAX)
			&& (ft_strlen(data->arg[i]) < 12) && (ft_strlen(data->arg[i]) > 0))
				data->a = ft_lstnew_int(nbr);
		else if ((nbr >= INT_MIN && nbr <= INT_MAX)
			&& (ft_strlen(data->arg[i]) < 12) && (ft_strlen(data->arg[i]) > 0))
		{
			temp = data->a;
			temp = ft_lstlast_int(data->a);
			temp->next = ft_lstnew_int(nbr);
		}
		else
			ft_error_n_out(data, 0);
		i++;
	}
}
