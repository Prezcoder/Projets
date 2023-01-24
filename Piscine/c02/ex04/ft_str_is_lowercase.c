/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 10:55:01 by fbouchar          #+#    #+#             */
/*   Updated: 2022/11/29 15:50:03 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 97 && str[i] <= 122)
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
/*#include <unistd.h>
#include <stdio.h>
int	main()
{
	char	str[] = "abcde";
	int i;

	i = 5;
	ft_str_is_lowercase(&str[i]);
	printf ("%d", ft_str_is_lowercase(str));
}*/
