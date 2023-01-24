/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 10:45:11 by fbouchar          #+#    #+#             */
/*   Updated: 2022/12/08 11:16:39 by fbouchar         ###   ########.fr       */
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
char	*ft_strrev(char *str)
{
	int i;
	int len;
	char temp;

	i = 0;
	len = ft_strlen(str);
	len--;
	while (len > 0)
	{
		temp = str[len];
		str[len] = str[i];
		str[i] = temp;
		i++;
		len--;
	}
	return (str);
}
#include <stdio.h>
int main()
{
	char c[10] = "allo";

	printf("%s\n", ft_strrev(c));
}
