/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 09:00:22 by fbouchar          #+#    #+#             */
/*   Updated: 2022/12/15 09:24:10 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
		ft_putstr("-2147483648");
    else if (nb >= 0 && nb < 10)
        ft_putchar(nb + '0');
    else if (nb < 0)
    {
        ft_putchar('-');
        ft_putnbr(nb * (-1));
    }
    else
    {
        ft_putnbr(nb / 10);
        ft_putnbr(nb % 10);
    }

}

int main()
{
    ft_putnbr(2635);
    write (1, "\n", 1);
}