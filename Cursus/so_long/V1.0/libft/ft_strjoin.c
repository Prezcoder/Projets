/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:10:42 by fbouchar          #+#    #+#             */
/*   Updated: 2023/02/22 11:49:08 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Alloue (avec malloc) et retourne une nouvelle
chaîne, résultat de la concaténation de s1 et s2.*/
char    *ft_strjoin(char *s1, char *s2)
{
    unsigned int    lens1;
    unsigned int    lens2;
    char            *newstr;
    if (!s1 || !s2)
        return (NULL);
    lens1 = ft_strlen(s1);
    lens2 = ft_strlen(s2);
    newstr = (char *)malloc(lens1 + lens2 + 1 * (sizeof(char)));
    if (!newstr)
        return (NULL);
    ft_memcpy(newstr, s1, lens1);
    ft_memcpy(newstr + lens1, s2, lens2);
    newstr[lens1 + lens2] = '\0';
    free(s1);
    return (newstr);
}
