/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:13:40 by fbouchar          #+#    #+#             */
/*   Updated: 2022/12/09 08:43:08 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 2 && argv[1][i] != '\0')
	{
		while (argv[1][i])
		{
			if ((argv[1][i] >= 'a' && argv[1][i] <= 'y')
				|| (argv[1][i] >= 'A' && argv[1][i] <= 'Y'))
				argv[1][i] += 1;
			else if (argv[1][i] == 'z' && argv[1][i] == 'Z')
				argv[1][i] -= 25;
			write (1, &argv[1][i], 1);
			i++;
		}
	}
	else
		write (1, "\n", 1);
}
			
