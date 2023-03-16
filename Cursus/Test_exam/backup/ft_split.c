/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 11:16:17 by fbouchar          #+#    #+#             */
/*   Updated: 2023/03/16 14:56:00 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_count_words(char *str)
{
	int	i;
	int count_words;

	i = 0;
	count_words = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i++;
	while (str[i])
	{
		count_words++;
		while (str[i] >= 33 && str[i] <= 126)
			i++;
		
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i++;
	}
	return (count_words);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char *ft_string(char *str)
{
	static int 	i;
	int			j;
	int			k;
	int			l;
	char 		*small_str;

	j = 0;
	l = 0;
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t')
			i++;
		while (str[i] >= 33 && str[i] <= 126)
		{
			i++;
			j++; 
		}
		break;
	}
	small_str = malloc(sizeof(char) * (j + 1));
	k = j;
	l = i - j;
	j = 0;
	while (j < k)
	{
		small_str[j] = str[l];
		j++;
		l++;
	}
	small_str[j] = '\0';
	return (small_str);
}

char    **ft_split(char *str)
{
	int	l;
	int j;
	char **tab;

	j = 0;
	l =	ft_count_words(str);
	tab = malloc(sizeof(char *) * l + 1);
	while (j < l)
	{
		tab[j++] = ft_string(str);
	}
	tab[j] = NULL;
	return (tab);
}



// int	main(void)
// {
// 	char **tab;
// 	int i;
// 	int	h;

// 	i = 0;
// 	h = 0;
// 	tab = ft_split("petit garcon damour");
// 	while (tab[i])
// 	{
// 		printf("%s", tab[i]);
// 		i++;
// 	}
// }