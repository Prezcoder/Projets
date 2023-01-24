/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 08:12:12 by fbouchar          #+#    #+#             */
/*   Updated: 2022/12/08 08:57:03 by fbouchar         ###   ########.fr       */
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
char	*ft_rev_print(char *str)
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
	ft_rev_print("allo");
}
