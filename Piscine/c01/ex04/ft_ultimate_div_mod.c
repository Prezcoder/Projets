/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 08:35:22 by fbouchar          #+#    #+#             */
/*   Updated: 2022/11/28 10:53:36 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	i;

	i = *a / *b;
	*b = *a % *b;
	*a = i;
}

/*#include <stdio.h>

int main()
{
	int i;
	int j;

	i = 5;
	j = 3;

	ft_ultimate_div_mod(&i, &j);
	printf("%d\n%d\n", i, j);
}*/
