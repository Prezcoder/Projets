/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 07:45:51 by fbouchar          #+#    #+#             */
/*   Updated: 2023/01/12 08:49:54 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*bzero() shall place n zero-valued
bytes in the area pointed to by s.*/
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
