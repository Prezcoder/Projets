/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 13:52:12 by fbouchar          #+#    #+#             */
/*   Updated: 2023/05/18 14:55:40 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main()
{
	int		i;
	int 	j;
	// int		length;
	// char 	*prompt;
	char	*name;
	t_data	data;

	i = 0;
	j = 0;
	data.path = ft_split(getenv("PATH"), ':');
	// prompt = ;
	data.lcmd.argv = ft_split(readline(ttyname(0)), ' ');
	while (data.path[j])
	{
		name = ft_strjoin(data.path[j], "/", 0);
		name = ft_strjoin(name, data.lcmd.argv[0], 1);
		i = access(name, X_OK);
		if (i == 0)
		{
			data.lcmd.cmdpath = name;
		}
		ft_printf("%i", i);
		j++;
	}
}