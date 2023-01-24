/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 09:04:07 by fbouchar          #+#    #+#             */
/*   Updated: 2022/12/01 13:42:29 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (s1[i] != '\0' && i != n)
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	if (s2[i] == '\0' || i == n)
	{
		return (0);
	}
	else
	{
		return (-s2[i]);
	}
}
/*#include <stdio.h>

int	main()
{
	int	i;

	i = 5;
	char c[] = "autobus";
	char b[] = "autogus";

	ft_strncmp(c, b, i);
	printf("%d\n", ft_strncmp(c, b, i));
}*/
