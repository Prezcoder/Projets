/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:05:09 by fbouchar          #+#    #+#             */
/*   Updated: 2022/12/12 13:32:58 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*tab;
	int	i;

	if (min >= max)
		return (NULL);
	tab = (int *)malloc(sizeof(int) * (max - min));
	if (tab == NULL)
		return (NULL);
	i = 0;
	while (min < max)
	{
		tab[i] = min;
		i++;
		min++;
	}
	return (tab);
}
/* #include <stdio.h>

int	main(void)
{
	int	i;
	int	*tab;

	tab = ft_range(22, 33);
	i = 0;
	while (i < 11)
	{
		printf("%d\n", tab[i]);
		i++;
	}
} */
