/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 10:16:59 by fbouchar          #+#    #+#             */
/*   Updated: 2022/12/01 13:52:46 by fbouchar         ###   ########.fr       */
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

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	int				n;

	i = 0;
	n = ft_strlen(dest);
	while (src[i] != '\0' && i != nb)
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
	char c[20] = " matin";
	char b[20] = "bon";
	unsigned int	g;

	g = 5;
	printf("%s\n", ft_strncat(b, c, g));
}*/
