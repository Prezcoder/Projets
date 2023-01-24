/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 08:00:39 by fbouchar          #+#    #+#             */
/*   Updated: 2022/12/14 08:11:49 by fbouchar         ###   ########.fr       */
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

int main()
{
	char c[] = " test";
	ft_rev_print(c);
}