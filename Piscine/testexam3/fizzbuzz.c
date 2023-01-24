/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 07:46:06 by fbouchar          #+#    #+#             */
/*   Updated: 2022/12/14 07:57:55 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main()
{
	int i;
	int j;

	i = 1;
	j = 0;
	while (i <= 100)
	{
		if (i % 3 == 0 && i % 5 == 0)
			write (1, "fizzbuzz", 8);
		else if (i % 5 == 0)
			write (1, "buzz", 4);
		else if (i % 3 == 0)
			write (1, "fizz", 4);
		else
		{	
			if (i >= 1 && i <= 9)
			{
				j = i + 48;
				write (1, &j, 1);
			}
			else
			{
				j = i / 10 + 48;
				write (1, &j, 1);
				j = i % 10 + 48;
				write (1, &j, 1);
			}
		}
		i++;
		write (1, "\n", 1);
	}
}