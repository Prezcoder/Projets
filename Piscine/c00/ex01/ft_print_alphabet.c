/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:28:55 by fbouchar          #+#    #+#             */
/*   Updated: 2022/11/25 07:37:03 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print_alphabet(void)
{
	char	f;

	f = 'a';
	while (f <= 'z')
	{
		write(1, &f, 1);
		f++;
	}
}
/*int main()
{
	ft_print_alphabet();
}*/
