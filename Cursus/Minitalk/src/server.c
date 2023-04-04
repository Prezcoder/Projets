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

#include "../includes/minitalk.h"

static t_server	*ft_init(void)
{
	static t_server	*data;

	if (!data)
	{
		data = malloc(sizeof(t_server));
		if (!data)
			exit(EXIT_FAILURE);
		data->letter = 0;
		data->bytes = 0;
		data->length = 0;
		data->client = 0;
		data->n = 0;
		data->words = NULL;
	}
	return (data);
}

static void	ft_restart(t_server *data)
{
	data->n = 0;
	data->bytes = 0;
	data->length = 0;
	free(data->words);
	data->words = NULL;
}

static void	ft_reform(int sig, t_server *data)
{
	data->letter = data->letter * 2;
	data->letter = data->letter + sig;
	data->bytes++;
	if (data->bytes == 32)
	{
		data->length = data->letter;
		data->words = malloc(sizeof(char) * (data->length + 1));
		if (!data->words)
			exit(EXIT_FAILURE);
		data->letter = 0;
	}
	else if ((data->bytes >= 40) && data->bytes % 8 == 0)
	{	
		data->words[data->n++] = data->letter;
		if (data->letter == 0)
		{
			ft_putstr(data->words);
			kill(data->client, SIGUSR2);
			ft_restart(data);
		}
		data->letter = 0;
	}
}

static void	ft_handler(int signum, siginfo_t *info, void *ucontent)
{
	t_server	*data;

	(void)ucontent;
	data = ft_init();
	if (data->client != info->si_pid)
	{	
		if (data->client != 0)
		{
			free(data->words);
			data->words = NULL;
		}
		data->client = info->si_pid;
		data->n = 0;
		data->bytes = 0;
		data->length = 0;
		data->letter = 0;
	}
	if (signum == SIGUSR1)
		ft_reform(0, data);
	else
		ft_reform(1, data);
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa_sign;

	ft_init();
	pid = getpid();
	ft_putstr("\033[0;36mServer PID: \033[0;37m");
	ft_putnbr(pid);
	ft_putstr("\n\033[0;33mUp and running. Ready to work!\033[0;37m\n");
	sa_sign.sa_sigaction = &ft_handler;
	sa_sign.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa_sign, NULL);
	sigaction(SIGUSR2, &sa_sign, NULL);
	while (1)
		pause ();
	free(ft_init);
	return (0);
}
