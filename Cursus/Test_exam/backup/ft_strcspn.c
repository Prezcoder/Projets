/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 09:33:11 by fbouchar          #+#    #+#             */
/*   Updated: 2023/03/23 09:51:22 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t	i;
	int	tab[256] = {0};
	

	i = 0;
	while (reject[i])
		tab[(int)reject[i++]] = 1;
	i = 0;
	while (s[i])
	{		
		if (tab[(int)s[i]] == 1)
			return (i);
		else
			i++;
	}
	return (i);
}