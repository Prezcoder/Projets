/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 10:45:22 by fbouchar          #+#    #+#             */
/*   Updated: 2022/12/14 07:24:40 by fbouchar         ###   ########.fr       */
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

int main(int argc, char **argv)
{
    int i;
    int j;

    i = 0;
    j = ft_strlen(&argv[1][i]);
    j--;
    if (argc == 3)
    {
        while (argv[1][i])
        {
            if (argv[1][i] == argv[1][j])
            {
                break;
            }
            write (1, &argv[1][i], 1);
            j--;
        }
        i++;
    }
}