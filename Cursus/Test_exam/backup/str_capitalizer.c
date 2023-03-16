/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:28:26 by fbouchar          #+#    #+#             */
/*   Updated: 2023/03/15 14:50:05 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_lowercase(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 65 && str[i] <= 90)
			str[i] += 32;
		i++;
	}
}

int	main(int argc, char **argv)
{
	int i;
	int j;

	i = 0;
	j = 1;
	while (j < argc)
	{
		ft_lowercase(argv[j]);
		while (argv[j][i])
		{
			if (argv[j][i - 1] == ' ' && (argv[j][i] >= 97 && argv[j][i] <= 122) || i == 0 && (argv[j][i] >= 97 && argv[j][i] <= 122))
			{
				argv[j][i] -= 32;
				write(1, &argv[j][i], 1);
			}
			else
				write(1, &argv[j][i], 1);
			i++;
		}
		i = 0;
		j++;
	}
	write(1, "\n", 1);
}