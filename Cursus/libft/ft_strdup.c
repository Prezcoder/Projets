/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 07:46:23 by fbouchar          #+#    #+#             */
/*   Updated: 2023/01/12 08:16:03 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*strdup() returns a pointer to a new string which is
a duplicate of the string s1. Memory for the new string is
obtained with malloc.*/
char	*ft_strdup(const char *s1)
{
	char	*new;
	int		i;
	int		size;

	size = ft_strlen(s1) + 1;
	i = 0;
	new = (char *)malloc(sizeof(char) * size);
	if (!new)
		return (NULL);
	ft_memcpy(new, s1, size);
	return (new);
}
