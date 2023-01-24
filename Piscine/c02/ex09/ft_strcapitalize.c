/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 12:45:36 by fbouchar          #+#    #+#             */
/*   Updated: 2022/11/29 14:20:54 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i - 1] >= 0 && str[i - 1] <= 32)
			|| (str[i - 1] >= 91 && str[i - 1] <= 96)
			|| (str[i - 1] <= 123 && str[i - 1] >= 127))
		{
			str[i] = str[i] - 32;
		}
		i++;
	}
	return (str);
}
#include <stdio.h>
int	main()
{
	char	str[] = "salut, coMment tu vas ? 42mots quarante-deux; cinquante+et+un";

	printf ("%s\n", ft_strcapitalize(str));
}
