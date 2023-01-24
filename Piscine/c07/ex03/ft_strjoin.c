/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 08:05:45 by fbouchar          #+#    #+#             */
/*   Updated: 2022/12/12 13:33:44 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str);
char	*ft_strcpy(char *dest, char *src);

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		j;
	int		k;
	char	*string;

	i = 0;
	k = 0;
	string = (char *)malloc(sizeof(strs));
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			string[k++] = strs[i][j++];
		}
		j = 0;
		while (sep[j] != '\0' && i != size - 1)
		{
			string[k++] = sep[j++];
		}
		i++;
	}
	string[k] = '\0';
	return (string);
}
/* #include <stdio.h>

int	main(void)
{
	char *sep = "-";
	char *strs[] = {"test1", "test2", "test3"};
	int size = 3;

	printf("%s\n", ft_strjoin(size, strs, sep));
} */