/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 09:03:10 by fbouchar          #+#    #+#             */
/*   Updated: 2023/04/12 09:10:03 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int	ft_putnbr_u(unsigned int n, int fd)
{
	const char	*base;
	int			nbr_len;
	int			temp;

	nbr_len = 0;
	base = "0123456789";
	if (n >= 10)
	{
		ft_putnbr_fd2(n / 10, fd);
		ft_putnbr_fd2(n % 10, fd);
	}
	else
	{
		temp = write(fd, &base[n], 1);
		if (temp < 0)
			return (-1);
	}
	nbr_len += ft_nbrlen_base(n, ft_strlen(base));
	return (nbr_len);
}

int	ft_putnbr_hexa(uintptr_t n, int fd, char format)
{
	const char	*base;
	const char	*base2;
	int			nbr_len;
	int			temp;

	nbr_len = 0;
	base = "0123456789abcdef";
	base2 = "0123456789ABCDEF";
	if (format == 'X')
		base = base2;
	if (n >= 16)
	{
		ft_putnbr_hexa(n / 16, fd, format);
		ft_putnbr_hexa(n % 16, fd, format);
	}
	else
	{
		temp = write(fd, &base[n], 1);
		if (temp < 0)
			return (-1);
	}
	nbr_len += ft_nbrlen_base(n, ft_strlen(base));
	return (nbr_len);
}

int	ft_putnbr_ptr(uintptr_t n, int fd)
{
	const char	*base;
	int			nbr_len;
	int			temp;

	nbr_len = 0;
	base = "0123456789abcdef";
	write(1, "0x", 2);
	if (n >= 16)
	{
		ft_putnbr_hexa(n / 16, fd, 'x');
		ft_putnbr_hexa(n % 16, fd, 'x');
	}
	else
	{
		temp = write(fd, &base[n], 1);
		if (temp < 0)
			return (-1);
	}
	nbr_len += ft_nbrlen_base2(n, ft_strlen(base));
	return (nbr_len + 2);
}

size_t	ft_nbrlen_base2(uintptr_t n, size_t base)
{
	size_t	i;

	i = 1;
	while (n >= (uintptr_t)base)
	{
		n /= base;
		i++;
	}
	return (i);
}
