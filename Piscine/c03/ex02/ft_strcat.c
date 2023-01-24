/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 09:00:33 by fbouchar          #+#    #+#             */
/*   Updated: 2022/12/01 13:44:42 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	l;

	l = 0;
	while (str[l] != '\0')
	{
		l++;
	}
	return (l);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	n;

	i = 0;
	n = ft_strlen(dest);
	while (src[i] != '\0')
	{
		dest[n + i] = src[i];
		i++;
	}
	dest[n + i] = '\0';
	return (dest);
}
/*#include <stdio.h>

int	main()
{
	char c[20] = "sal";
	char b[20] = "toi mon ami";

	printf("%s\n", ft_strcat(b, c));
}*/
