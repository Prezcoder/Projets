/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 12:47:15 by fbouchar          #+#    #+#             */
/*   Updated: 2023/04/19 09:28:00 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_iter_list(t_data *data)
{
	int		i;
	t_stack	*temp;
	
	i = 0;
	temp = data->a;
	while (temp != NULL)
	{
		if (temp->number == data->high)
			data->to_last = i;
		i++;
		// ft_printf("List A:%i", temp->number);
		data->last = temp->number;
		temp = temp->next;
	}
	
}

void	ft_iter_listb(t_data *data)
{
	while (data->b)
	{
		ft_printf("List B:%i", data->b->number);
		data->b = data->b->next;
	}
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

	temp = NULL;
	while (data->arg[i])
	{
		nbr = ft_atoi(data->arg[i]);
		if (data->a == NULL && (nbr > INT_MIN && nbr < INT_MAX))
				data->a = ft_lstnew_int(nbr);
		else if (nbr > INT_MIN && nbr < INT_MAX)
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
