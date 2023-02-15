/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:10:42 by fbouchar          #+#    #+#             */
/*   Updated: 2023/02/15 10:59:13 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Alloue (avec malloc) et retourne une nouvelle
chaîne, résultat de la concaténation de s1 et s2.*/
char	*ft_strjoin(char *saved, char *buf)
{
	char			*str;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (!saved)
	{
		saved = (char *)malloc(sizeof(char) * 1);
		saved[0] = '\0';
	}
	if (!saved || !buf)
		return (NULL);
	str = malloc_join(saved, buf);
	while (saved[i])
	{
		str[i] = saved[i];
		i++;
	}
	while (buf[j])
		str[i++] = buf[j++];
	str[i] = '\0';
	free(saved);
	return (str);
}
