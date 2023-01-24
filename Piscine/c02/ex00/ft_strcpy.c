/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 14:50:44 by fbouchar          #+#    #+#             */
/*   Updated: 2022/11/29 14:28:33 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/*#include <unistd.h>
int	main()
{
	int i;

	i = 0;
	char c[] = "bon matin";
	char d[15];

	ft_strcpy(d, c);
	while (d[i] != '\0')
	{
		write (1, &d[i], 1);
		i++;
	}
}*/
