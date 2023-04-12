/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 08:25:27 by fbouchar          #+#    #+#             */
/*   Updated: 2023/04/12 09:06:59 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

static int	ft_letter(va_list args, const char format)
{
	if (format == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (format == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (format == 'p')
		return (ft_putnbr_ptr(va_arg(args, uintptr_t), 1));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr_fd2(va_arg(args, int), 1));
	else if (format == 'u')
		return (ft_putnbr_u(va_arg(args, unsigned int), 1));
	else if (format == 'x' || format == 'X')
		return (ft_putnbr_hexa(va_arg(args, unsigned int), 1, format));
	else if (format == '%')
		return (ft_putchar('%'));
	else
		return (-1);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		length;

	i = 0;
	length = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			length += ft_letter(args, s[i + 1]);
			i++;
		}
		else
		{
			length += ft_putchar(s[i]);
		}
		i++;
	}
	va_end(args);
	return (length);
}
