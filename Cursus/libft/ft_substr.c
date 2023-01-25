/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:41:50 by fbouchar          #+#    #+#             */
/*   Updated: 2023/01/25 08:58:17 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Alloue (avec malloc) et retourne une chaîne de caractères issue 
de la chaîne ’s’. Cette nouvelle chaîne commence à l’index ’start’ et
a pour taille maximale ’len’.*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	size;

	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	size = ft_strlen(s + start);
	if (size < len)
		len = size;
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr || !s)
		return (NULL);
	ft_strlcpy(ptr, s + start, len + 1);
	return (ptr);
}
