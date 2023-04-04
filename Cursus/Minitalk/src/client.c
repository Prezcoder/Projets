/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 10:28:19 by fbouchar          #+#    #+#             */
/*   Updated: 2023/04/04 14:18:33 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static void	ft_send_bits(int pid, int octet, int nbbit)
{
	while (nbbit != 0)
	{
		nbbit--;
		if ((octet >> nbbit & 1) == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(30);
	}
}

static void	ft_sa_handler(int sig)
{
	if (sig == SIGUSR2)
	{	
		ft_putstr("\033[0;34mThe Server received your message\033[0;37m\n");
		exit(EXIT_SUCCESS);
	}
}

static void	ft_check_pid(int pid)
{
	if (kill(pid, 0) < 0)
	{	
		ft_putstr("\033[0;31mError: Wrong PID\033[0;37m\n");
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char **argv)
{
	int					pid;
	int					i;
	int					length;
	struct sigaction	sa;

	sa.sa_handler = &ft_sa_handler;
	sigaction(SIGUSR2, &sa, NULL);
	i = 0;
	length = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		ft_check_pid(pid);
		length = ft_strlen(argv[2]);
		ft_send_bits(pid, length, 32);
		while (argv[2][i])
			ft_send_bits(pid, argv[2][i++], 8);
		ft_send_bits(pid, argv[2][i], 8);
		sleep(15);
	}
	else
	{
		ft_putstr("\033[0;31mError: Wrong format.\033[0;37m\n");
		exit(EXIT_FAILURE);
	}
}
