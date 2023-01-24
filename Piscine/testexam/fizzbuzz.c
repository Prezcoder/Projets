/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:40:55 by fbouchar          #+#    #+#             */
/*   Updated: 2022/12/12 15:53:02 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(void)
{
    int i;
    int j;

    i = 1;
    j = 0;
    while (i <= 100)
    {
        if (i % 15 == 0)
            write (1, "fizzbuzz", 8);
        else if (i % 5 == 0)
            write (1, "buzz", 4);
        else if (i % 3 == 0)
            write (1, "fizz", 4);
        else
        {
            if (i >= 0 && i <= 9)
            {
                j = i + 48;
                write (1, &j, 1);
            }
            else
            {
                j = (i / 10) + 48;
                write (1, &j, 1);
                j = (i % 10) + 48;
                write (1, &j, 1);
            }
        }
        write (1, "\n", 1);
        i++;
    }
    return (0);
}