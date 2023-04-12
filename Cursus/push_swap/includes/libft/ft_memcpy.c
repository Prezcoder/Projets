/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:51:23 by fbouchar          #+#    #+#             */
/*   Updated: 2023/01/18 08:53:40 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*memcpy() is used to copy a block of 
memory from a location to another.*/
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dest;
	const unsigned char	*source;

	if (!dst || !src)
		return (dst);
	source = (unsigned char *)src;
	dest = (unsigned char *)dst;
	i = 0;
	while (n--)
	{
		dest[i] = source[i];
		i++;
	}
	return (dest);
}
