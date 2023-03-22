/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 09:16:49 by fbouchar          #+#    #+#             */
/*   Updated: 2023/03/21 09:37:14 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	ft_reform(int sig)
{
	static int	letter;
	static int 	i;
	static int	n;
	char 		words[1000000];

	letter = letter * 2;
	letter = letter + sig;
	i++;
	if (letter != 0)
	{	
		if (i == 8)
		{
			words[n] = letter;
			n++;
			i = 0;
			letter = 0;
		}
	}
	else
	{
		// n++;
		// words[n] = '\0';
		ft_putstr_fd(words, 1);
		n = 0;
	}
}

void	ft_handler(int signum, siginfo_t *info, void *ucontent)
{
	(void)ucontent;
	(void)info;
	if (signum == SIGUSR1)
		ft_reform(0);
	else
		ft_reform(1);
} 

int main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_putnbr_fd(pid, 1);
	struct sigaction sa_sign = {0};
	sa_sign.sa_sigaction = &ft_handler;
	sa_sign.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa_sign, NULL);
	sigaction(SIGUSR2, &sa_sign, NULL);
	while (1)
	{
		;
	}

}