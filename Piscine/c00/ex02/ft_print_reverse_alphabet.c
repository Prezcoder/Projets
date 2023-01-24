/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:49:35 by fbouchar          #+#    #+#             */
/*   Updated: 2022/11/25 07:43:28 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print_reverse_alphabet(void)
{
	char	f;

	f = 'z';
	while (f >= 'a')
	{
		write(1, &f, 1);
		f--;
	}
}
/*int main()
{
	ft_print_reverse_alphabet();
}*/
