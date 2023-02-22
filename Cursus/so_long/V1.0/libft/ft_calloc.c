/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 08:45:50 by fbouchar          #+#    #+#             */
/*   Updated: 2023/01/12 08:49:55 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*“calloc” or “contiguous allocation” method 
is used to dynamically allocate the specified 
number of blocks of memory of the specified type. 
It is very much similar to malloc() but has 
two different points and these are:

It initializes each block with a default value ‘0’.
It has two parameters or arguments as compare to malloc().*/
void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = (malloc(count * size));
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}
