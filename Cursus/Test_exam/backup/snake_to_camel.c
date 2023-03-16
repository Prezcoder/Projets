/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snake_to_camel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:40:42 by fbouchar          #+#    #+#             */
/*   Updated: 2023/03/09 15:06:13 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (1);
	}
	while (argv[1][i])
	{
		if (argv[1][i] == '_')
		{
			i++;
			if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
				argv[1][i] -= 32;
			write(1, &argv[1][i], 1);
		}
		else if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
		{
			argv[1][i] += 32;
			write(1, &argv[1][i], 1);
		}
		else
			write(1, &argv[1][i], 1);
		i++;
	}
	write(1, "\n", 1);
}