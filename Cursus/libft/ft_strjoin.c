/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:10:42 by fbouchar          #+#    #+#             */
/*   Updated: 2023/02/15 10:09:17 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Alloue (avec malloc) et retourne une nouvelle
chaîne, résultat de la concaténation de s1 et s2.*/
char	*ft_strjoin(char *s1, char *s2)
{
	char	*ptr;
	int		size_s1;
	int		size_s2;

	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	if (!s1 || !s2)
		return (NULL);
	ptr = (char *)malloc(sizeof(char) * (size_s1 + size_s2) + 1);
	if (!ptr)
		return (NULL);
	ft_memcpy(ptr, s1, size_s1);
	ft_memcpy(ptr + size_s1, s2, size_s2);
	ptr[size_s1 + size_s2] = '\0';
	free (s1);
	return (ptr);
}
