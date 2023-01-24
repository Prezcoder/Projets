/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 08:20:32 by fbouchar          #+#    #+#             */
/*   Updated: 2022/12/09 08:35:46 by fbouchar         ###   ########.fr       */
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

char	*ft_strrev2(char *str)
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
int main()
{
	char c[10] = "salut";
	printf("%s\n", ft_strrev2(c));
}
