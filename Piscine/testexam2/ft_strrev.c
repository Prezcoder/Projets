/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 08:44:53 by fbouchar          #+#    #+#             */
/*   Updated: 2022/12/13 09:03:38 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

char    *ft_strrev(char *str)
{
    int i;
    int j;
    char temp;

    i = ft_strlen(str);
    j = 0;
    i--;
    while (i > 0)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i--;
        j++;
    }
    return (str);
}
#include <stdio.h>

int main(void)
{
    char c[10] = "allo";
    printf("%s\n", ft_strrev(c));
}