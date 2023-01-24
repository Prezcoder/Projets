/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 10:24:28 by fbouchar          #+#    #+#             */
/*   Updated: 2022/12/01 13:36:51 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	if (s2[i] == '\0')
	{
		return (0);
	}
	else
	{
		return (-s2[i]);
	}
}
/*#include <stdio.h>
#include <string.h>

int	main()
{
	char c[] = "autobus";
	char b[] = "";

	ft_strcmp(c, b);
	printf("%d\n", ft_strcmp(c, b));

	printf("%i\n", strcmp(c, b));
}*/
