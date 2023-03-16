/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 10:23:20 by fbouchar          #+#    #+#             */
/*   Updated: 2023/03/16 10:49:47 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

char    *ft_strdup(char *src)
{
	char 	*copy;
	int		i;
	int 	j;
	int		length;

	i = 0;
	j = 0;
	length = ft_strlen(src);
	copy = malloc(sizeof(char) * length + 1);
	if (!copy)
		return (NULL);
	while (src[i])
	{
		copy[j] = src[i];
		i++;
		j++;
	}
	copy[j] = '\0';
	return (copy);
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("%s", ft_strdup("allo"));
// }