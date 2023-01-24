 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 08:09:12 by fbouchar          #+#    #+#             */
/*   Updated: 2022/11/30 15:52:58 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
/*#include <stdio.h>
int	main()
{
	int	i;

	i = 0;
	char c[] = "bon matin";
	char d[] = "salut bonjourjfjfj";

	int n;

	n = 9;

	printf("%s\n", ft_strncpy(d, c, n));
}*/
