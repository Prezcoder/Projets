/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:39:18 by fbouchar          #+#    #+#             */
/*   Updated: 2022/12/07 09:39:49 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str);

int	main(int argc, char **argv)
{
	(void) argc;
	ft_putstr(argv[0]);
	ft_putstr("\n");
}

void	ft_putstr(char *str)
{
	while (*str)
		write (1, str++, 1);
}
