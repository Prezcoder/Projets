/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 10:41:10 by fbouchar          #+#    #+#             */
/*   Updated: 2022/11/29 15:48:44 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 48 && str[i] <= 57)
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
	char str[] = "///";
	int i;

	i = 5;
	ft_str_is_numeric(&str[i]);
	printf ("%d", ft_str_is_numeric(str));
}*/
