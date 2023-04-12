/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 08:26:36 by fbouchar          #+#    #+#             */
/*   Updated: 2023/04/12 09:10:21 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (write(1, "(null)", 6));
	while (s[i])
		i++;
	return (write(1, s, i));
}

int	ft_putnbr_fd2(int n, int fd)
{
	const char	*base;
	int			nbr_len;

	nbr_len = 0;
	base = "0123456789";
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (n < 0)
	{
		ft_putchar('-');
		nbr_len += ft_putnbr_fd2(-n, fd);
	}
	else if (n >= 10)
	{
		ft_putnbr_fd2(n / 10, fd);
		ft_putnbr_fd2(n % 10, fd);
	}
	else
		write(fd, &base[n], 1);
	nbr_len += ft_nbrlen_base(n, ft_strlen(base));
	return (nbr_len);
}

size_t	ft_nbrlen_base(long long int n, size_t base)
{
	size_t	i;

	i = 1;
	while (n >= (long long int)base)
	{
		n /= base;
		i++;
	}
	return (i);
}
