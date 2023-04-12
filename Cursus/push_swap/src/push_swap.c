/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:22:47 by fbouchar          #+#    #+#             */
/*   Updated: 2023/04/12 15:14:52 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_iter_list(t_data *data)
{
	while (data->a)
	{
		ft_printf("%i", data->a->number);
		data->a = data->a->next;
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

void	ft_init_data(t_data *data)
{
	if (!data)
	{
		data->arg = NULL;
		data->a = NULL;
		data->b = NULL;
		data->i = 0;
	}
}

void	ft_check_doubles(t_data *data)
{
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	while (data->arg[i])
	{
		data->arg[j] = data->arg[i];
		i++;
		if (data->arg[j] == data->arg[i])
		{	
			ft_putendl_fd("Error", 2);
			exit(EXIT_FAILURE);
		}
	}
}

void	ft_check_number(t_data *data, int i)
{
	int	j;

	j = 0;
	if (data->arg[i] == NULL)
	{	
		ft_putendl_fd("Error", 2);
		ft_freeall(data->arg);
		exit(EXIT_FAILURE);
	}
	while (data->arg[i])
	{
		while (data->arg[i][j])
		{
			if (((data->arg[i][j] == '-') && (!(data->arg[i][j + 1] >= '0'
					&& data->arg[i][j + 1] <= '9')))
				|| data->arg[i][j + 1] == '-')
			{	
				ft_putendl_fd("Error", 2);
				ft_freeall(data->arg);
				exit(EXIT_FAILURE);
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	ft_make_split(char *arg, t_data *data)
{
	long int	nbr;
	t_stack		*temp;

	temp = NULL;
	data->arg = ft_split(arg, ' ');
	ft_check_number(data, 0);
	// ft_check_doubles(data);
	while (data->arg[data->i])
	{
		nbr = ft_atoi(data->arg[data->i]);
		if (nbr > INT_MIN && nbr < INT_MAX)
		{
			temp = data->a;
			data->a = ft_lstnew_int(nbr);
			data->a->next = temp;
		}
		else
		{
			ft_free_stack(data->a);
			exit(EXIT_FAILURE);
		}
		data->i++;
	}
	ft_freeall(data->arg);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = malloc(sizeof(*data));
	if (!data)
		return (0);
	ft_init_data(data);
	if (argc == 2)
	{
		ft_make_split(argv[1], data);
	}
	ft_iter_list(data);
	// else if (argc > 3)
	// {
	// }
	// else
	// 	ft_printf("%s", argv[0]);
}
