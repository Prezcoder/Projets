/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:13:30 by fbouchar          #+#    #+#             */
/*   Updated: 2023/03/09 15:05:53 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main()
{
	int	i;
	int	j;
	
	i = 1;
	j = 0;
	while(i <= 100)
	{
		if (i % 3 == 0 && i % 5 == 0)
			write(1, "fizzbuzz", 8);
		else if (i % 3 == 0)
			write(1, "fizz", 4);
		else if (i % 5 == 0)
			write(1, "buzz", 4);
		
		else if (i > 0 && i <= 9)
		{
			j = i + 48;
			write(1, &j, 1);
		}
		else
		{
			j = i / 10 + 48;
			write(1, &j, 1);
			j = i % 10 + 48;
			write(1, &j, 1);
		}
		i++;
		write(1, "\n", 1);
	}
	return (0);
}