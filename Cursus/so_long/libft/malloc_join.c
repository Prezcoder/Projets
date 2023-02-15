/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_join.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 11:00:15 by fbouchar          #+#    #+#             */
/*   Updated: 2023/02/15 11:00:31 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*malloc_join(char *saved, char *buf)
{
	char	*str;

	str = malloc((((ft_strlen(saved)) + ft_strlen(buf)) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	return (str);
}