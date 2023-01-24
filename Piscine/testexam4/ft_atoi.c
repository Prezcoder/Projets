/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 08:34:35 by fbouchar          #+#    #+#             */
/*   Updated: 2022/12/15 08:48:33 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
    int i;
    int result;
    int sign;

    i = 0;
    result = 0;
    sign = 1;
    while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
        i++;
    if (str[i] == '+')
        i++;
    else if (str[i] == '-')
    {
        sign = -1;
        i++;
    }
    while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + str[i] - '0';
        i++;
    }
    return (result * sign);
}

#include <stdio.h>

int main ()
{
    printf("%d\n", ft_atoi("  --1234bs8484"));
}