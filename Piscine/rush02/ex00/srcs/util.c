/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 17:57:24 by francoma          #+#    #+#             */
/*   Updated: 2022/12/11 16:47:43 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int	is_space(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

int	ft_valid_unsigned_int(char *str)
{
	int		i;
	int		maybe_too_big;
	char	*max_nb;
	int		digits_qty;

	while (*str == '0' || is_space(*str) || *str == '+' || *str == '-')
		str++;
	if (!(*str >= '0' && *str <= '9'))
		str--;
	digits_qty = 0;
	while (str[digits_qty] >= '0' && str[digits_qty] <= '9')
		digits_qty++;
	if (digits_qty > 10 || digits_qty == 0)
		return (0);
	maybe_too_big = 10 == digits_qty;
	max_nb = "4294967295";
	i = -1;
	while (++i < digits_qty)
	{
		if (maybe_too_big && str[i] > max_nb[i])
			return (0);
		if (str[i] < max_nb[i])
			maybe_too_big = 0;
	}
	return (1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	diff;

	diff = 0;
	while (diff == 0 && (*s1 || *s2))
		diff = *s1++ - *s2++;
	return (diff);
}
