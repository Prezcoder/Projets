/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 10:24:31 by fbouchar          #+#    #+#             */
/*   Updated: 2022/12/13 12:11:11 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;

	i = 0;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	*range = (int *)malloc(sizeof(int) * (max - min));
	if (!*range)
		return (-1);
	while (i < max - min)
	{
		(*range)[i] = min + i;
		i++;
	}
	return (i);
}
/* #include <stdio.h>

int	main(void)
{
	int *range = NULL;
	int min = 3;
	int max = -1;

	printf("%i\n", ft_ultimate_range(&range, min ,max));
} */
