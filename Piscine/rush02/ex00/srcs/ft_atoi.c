/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 18:11:37 by francoma          #+#    #+#             */
/*   Updated: 2022/12/11 16:54:52 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*skip_spaces(char *str)
{
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	return (str);
}

char	*get_sign(char *str, int *sign)
{
	*sign = 1;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			*sign *= -1;
		str++;
	}
	return (str);
}

int	count_digits(char *str)
{
	int	i;

	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	return (i);
}

long	ft_pow(int base, int exp)
{
	long	result;
	int		i;

	result = 1;
	i = 0;
	while (i++ < exp)
		result *= base;
	return (result);
}

long	ft_atoi(char *str)
{
	int		sign;
	int		digit_count;
	int		i;
	long	result;

	str = skip_spaces(str);
	str = get_sign(str, &sign);
	digit_count = count_digits(str);
	result = 0;
	i = 0;
	while (i < digit_count)
	{
		result += (str[digit_count - i - 1] - '0') * ft_pow(10, i);
		i++;
	}
	return (sign * result);
}
