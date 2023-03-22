/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 10:28:19 by fbouchar          #+#    #+#             */
/*   Updated: 2023/03/21 15:22:40 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	ft_send_bits(int pid, char i)
{
	int	bit;

	bit = 8;
	(void)pid;
	while (bit != 0)
	{
		bit--;
		if ((i >> bit & 1) == 0)
		{	
			kill(pid, SIGUSR1);
			// write(1, "0", 1);
		}
		else
		{
			kill(pid, SIGUSR2);
			// write(1, "1", 1);
		}
		usleep(30);
	}
}

#include <stdio.h>
int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		while (argv[2][i])
		{
			ft_send_bits(pid, argv[2][i]);
			i++;
		}
		i++;
		ft_send_bits(pid, argv[2][i]);
	}
	else
	{
		// ft_printf("Error: wrong format.\n");
		return (1);
	}
	return (0);
}