/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 10:54:15 by fbouchar          #+#    #+#             */
/*   Updated: 2023/08/28 14:22:18 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	void	*ptr;
	int		x;

	x = 0;
	ptr = &x;
	ft_printf("%x", -98840);
	ft_printf("%d\n", ft_printf("%x", -98840));
	printf("%x", -98840);
	printf("%d\n", printf("%x", -98840));
}
