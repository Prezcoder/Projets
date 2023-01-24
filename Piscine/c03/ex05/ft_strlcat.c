/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 08:11:36 by fbouchar          #+#    #+#             */
/*   Updated: 2022/12/01 11:10:00 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned	int	i;
	unsigned	int	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	if (size < i)
	{
		while (src[j])
			j++;
		return (size + j);
	}
	while (size > 0 && i < size - 1 && src[j])
		dest[i++] = src[j++];
	dest[i] = '\0';
	while (src[j++])
		i++;
	return (i);
}
#include <stdio.h>
#include <string.h>

int	main()
{
	char c[20] = " matin";
	char b[20] = "bon";
	unsigned int	g;

	g = 5;
	printf("%d\n", ft_strlcat(b, c, g));
	printf("%lu\n", strlcat(b, c, g));
}
