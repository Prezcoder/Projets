/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 07:51:11 by fbouchar          #+#    #+#             */
/*   Updated: 2022/12/13 07:59:26 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

char *ft_rev_print (char *str)
{
    int i;

    i = ft_strlen(str);
    i--;
    while (i >= 0)
    {
        write (1, &str[i], 1);
        i--;
    }
    write (1, "\n", 1);
    return (str);
}

#include <stdio.h>

int main()
{
    char *str = "bonjour";
    ft_rev_print(str);
}
