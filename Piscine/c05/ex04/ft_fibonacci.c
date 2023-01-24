/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:38:42 by fbouchar          #+#    #+#             */
/*   Updated: 2022/12/05 10:52:27 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	if (index == 1 || index == 2)
		return (1);
	if (index == 0)
		return (0);
	if (index > 2)
		index = ft_fibonacci(index - 1) + ft_fibonacci(index - 2);
	return (index);
}

/*#include <stdio.h>

int	main()
{
	printf("%i\n", ft_fibonacci(14));
}*/
