/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:52:57 by fbouchar          #+#    #+#             */
/*   Updated: 2022/12/05 15:20:21 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	i;

	i = 1;
	if (nb < 0)
		return (0);
	while (i < (nb / i))
		i++;
	if (nb == i * i)
		return (i);
	else
		return (0);
}

/*#include <stdio.h>

int main()
{
	printf("%i\n", ft_sqrt(1));
}*/
