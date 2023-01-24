/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 08:57:06 by fbouchar          #+#    #+#             */
/*   Updated: 2022/12/14 09:02:31 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char    *ft_strcpy(char *s1, char *s2)
{
    int i;

    i = 0;
    while (s2[i])
    {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
    return (s1);
}

#include <stdio.h>

int main()
{
    char s1[10];
    char s2[] = "allo";
    printf("%s\n", ft_strcpy(s1, s2));
}