/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 11:31:14 by fbouchar          #+#    #+#             */
/*   Updated: 2022/12/01 13:55:29 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (to_find[j] == '\0')
	{
		return (str);
	}
	while (str[i] != '\0')
	{
		while (to_find[j] == str[i + j])
		{
			j++;
			if (to_find[j] == '\0')
			{
				return (&str[i]);
			}
		}
		i++;
        j = 0;
	}
	return (0);
}
/*#include <stdio.h>

int	main()
{
	char c[30] = "il fait meau mon amour";
	char b[30] = "mon";

	ft_strstr(c, b);
	printf("%s\n", ft_strstr(c, b));
}*/
