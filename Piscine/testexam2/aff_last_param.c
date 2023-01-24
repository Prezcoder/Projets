/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_last_param.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 08:00:10 by fbouchar          #+#    #+#             */
/*   Updated: 2022/12/13 08:06:59 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    ft_putstr( char *str)
{
    int i;

    i = 0;
    while (str[i])
        write (1, &str[i++], 1);
}

int main(int argc, char **argv)
{
    if (argc >= 2)
    {
        ft_putstr(argv[argc - 1]);
    }
    ft_putstr("\n");
}