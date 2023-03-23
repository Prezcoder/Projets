/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 14:23:17 by fbouchar          #+#    #+#             */
/*   Updated: 2023/03/23 09:06:19 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
int	ft_count(char *str)
{
	int i;
	int count;
	
	i = 0;
	count = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	while (str[i])
	{
		count++;
		while (str[i] >= 33 && str[i] <= 126)
			i++;
		while (str[i] == ' ' || str[i] == '\t'  || str[i] == '\n')
			i++;
	}
	return (count);
}

char *ft_string(char *str)
{
	static int	h;
	int j;
	char *word;

	j = 0;
	word = malloc(sizeof(char) * ft_strlen(str) + 1);
	while (str[h] == ' ' || str[h] == '\t')
			h++;
	while ((str[h] >= 33 && str[h] <= 126) && str[h])
			word[j++] = str[h++];
	word[j] = '\0';
	return (word);
}

char    **ft_split(char *str)
{
	char **tab;
	int j;
	int l;
	
	j = 0;
	l = ft_count(str);
	tab = malloc(sizeof(char *) * l + 1);
	while (j < l)
		tab[j++] = ft_string(str);
	tab[j] = NULL;
	return (tab);
}

int	main (void)
{
	char **tab;
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	tab = ft_split("petit garcon damour allo salut");
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
}