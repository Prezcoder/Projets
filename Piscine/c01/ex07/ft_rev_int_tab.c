/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:18:12 by fbouchar          #+#    #+#             */
/*   Updated: 2022/11/28 14:29:29 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	temp;

	i = 0;
	while (tab[i] != size)
	{
		temp = tab[i];
		tab[i] = tab[size - 1];
		tab[size - 1] = temp;
		i++;
		size--;
	}
}

/*#include <stdio.h>

int	main()
{
	int tab[5] = {1, 2, 3, 4, 5};

	ft_rev_int_tab(tab, 5);
	int j;

	j = 0;
	while (j != 5)
	{
		printf("%d\n", tab[j]);
		j++;
	}
}*/
