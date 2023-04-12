/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:47:01 by fbouchar          #+#    #+#             */
/*   Updated: 2023/01/16 13:22:07 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Alloue (avec malloc) et retourne une copie de la chaîne ’s1’, 
sans les caractères spécifiés dans ’set’ au début et à la fin 
de la chaîne de caractères.*/
char	*ft_strtrim(char const *s1, char const *set)
{
	char		*result;
	int			i;
	int			j;

	i = 0;
	j = ft_strlen(s1);
	if (!s1 || !set)
		return (NULL);
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (j > i && ft_strchr(set, s1[j - 1]))
		j--;
	result = malloc(sizeof(char) * (j - i) + 1);
	if (!result)
		return (NULL);
	ft_strlcpy(result, s1 + i, (j - i) + 1);
	return (result);
}
