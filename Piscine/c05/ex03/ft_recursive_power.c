/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:27:18 by fbouchar          #+#    #+#             */
/*   Updated: 2022/12/05 10:38:09 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	if (power > 1)
		nb = nb * ft_recursive_power(nb, power - 1);
	return (nb);
}

/*#include <stdio.h>

int	main()
{
	printf("%i\n", ft_recursive_power(5, 4));
}*/
