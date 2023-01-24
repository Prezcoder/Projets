/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 08:16:34 by fbouchar          #+#    #+#             */
/*   Updated: 2022/11/28 10:50:45 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

/*#include <stdio.h>

int main()
{
	int i;
	int j;
	int div;
	int mod;

	i = 6;
	j = 2;

	ft_div_mod(i, j, &div, &mod);
	printf("%d\n%d\n", div, mod);
}*/
