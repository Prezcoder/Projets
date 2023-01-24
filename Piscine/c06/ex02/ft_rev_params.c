/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 07:25:44 by fbouchar          #+#    #+#             */
/*   Updated: 2022/12/06 07:48:57 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str);

void	ft_putchar(char c);

int	main(int argc, char **argv)
{
	while (argc > 1)
	{
		ft_putstr(argv[argc - 1]);
		ft_putchar('\n');
		argc--;
	}
}

void	ft_putstr(char *str)
{
	while (*str)
		write (1, str++, 1);
}

void	ft_putchar(char c)
{
	write (1, &c, 1);
}
