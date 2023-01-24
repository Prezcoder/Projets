/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 11:00:18 by fbouchar          #+#    #+#             */
/*   Updated: 2022/11/29 15:51:18 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 65 && str[i] <= 90)
		{
			i++;
		}
		else
		{
			return (0);
		}
	}
	return (1);
}
/*#include <stdio.h>
int	main()
{
	char	str[] = "";
	int i;

	i = 5;
	ft_str_is_uppercase(&str[i]);
	printf ("%d", ft_str_is_uppercase(str));
}*/
