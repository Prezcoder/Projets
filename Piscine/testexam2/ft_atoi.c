/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 09:06:17 by fbouchar          #+#    #+#             */
/*   Updated: 2022/12/13 10:44:01 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
    int i;
    int sign;
    int result;

    i = 0;
    result = 0;
    sign = 1;
    while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
        i++;
    if (str[i] == '-')
    {
        sign = -1;
        i++;
    }
    else if (str[i] == '+')
        i++;
    while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + str[i] - '0';
        i++;
    }
    return (result * sign);
}
#include <stdio.h>
#include <stdlib.h>

int main()
{
	printf("%d\n", ft_atoi(" -+1234ab567"));
}