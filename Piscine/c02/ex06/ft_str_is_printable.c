/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 11:06:45 by fbouchar          #+#    #+#             */
/*   Updated: 2022/11/29 15:52:02 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 32 && str[i] <= 126)
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
	char	str[] = "	";
	int i;

	i = 5;
	ft_str_is_printable(&str[i]);
	printf ("%d", ft_str_is_printable(str));
}*/
