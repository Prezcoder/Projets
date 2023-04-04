/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:11:13 by fbouchar          #+#    #+#             */
/*   Updated: 2023/03/27 12:43:49 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int     *ft_rrange(int start, int end)
{
	int l;
	int i;
	int *tab;

	l = 0;
	i = 0;
	if (start > end)
	{	
		l = start - end + 1;	
		tab = malloc(sizeof(int) * l + 1);
		while(l--)
			tab[i++] = end++;
	}
	else
	{	
		l = end - start + 1;
		tab = malloc(sizeof(int) * l + 1);
		while (l--)
			tab[i++] = end--;
	}
	tab[i] = '\0';
	return (tab);
}

