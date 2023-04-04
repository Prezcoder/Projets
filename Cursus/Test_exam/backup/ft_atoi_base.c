/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 09:53:38 by fbouchar          #+#    #+#             */
/*   Updated: 2023/03/23 10:29:58 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi_base(const char *str, int str_base)
{
	int i;
	int sign;
	int result;

	i = 0;
	sign = 1;
	result = 0;
	if (str[i] == '-')
	{	
		sign = -1;
		i++;
	}
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			result = result * str_base + str[i] - '0';
		else if (str[i] >= 'a' && str[i] <= 'f')
			result = result * str_base + str[i] - 'a' + 10;
		else if (str[i] >= 'A' && str[i] <= 'F')
			result = result * str_base + str[i] - 'A' + 10;
		else
			return (result * sign);
		i++;
	}
	return (result * sign);
}

// #include <stdio.h>

// int main()
// {
// 	printf("%d", ft_atoi_base("Ceci permet de decouvrir le fonctionnement de ton ft_atoi_base.", 16));
// }