/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paramsum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:33:05 by fbouchar          #+#    #+#             */
/*   Updated: 2023/03/09 15:06:30 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
	int	j;

	j = 0;
	(void)argv;
	if (argc < 2)
		write(1, "0\n", 2);
	else if (argc > 1)
	{
		if (argc > 0 && argc <= 9)
		{
			j = (argc - 1) + 48;
			write(1, &j, 1);
		}
		else
		{
		j = (argc - 1) / 10 + 48;
		write(1, &j, 1);
		j = (argc - 1) % 10 + 48;
		write(1, &j, 1);
		}
		write(1, "\n", 1);
	}
	
}