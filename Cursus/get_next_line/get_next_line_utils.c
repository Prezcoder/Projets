/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:39:05 by fbouchar          #+#    #+#             */
/*   Updated: 2023/02/15 09:59:10 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*malloc_join(char *saved, char *buf)
{
	char	*str;

	str = malloc((((ft_strlen(saved)) + ft_strlen(buf)) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	return (str);
}

char	*ft_strjoin(char *saved, char *buf)
{
	char			*str;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (!saved)
	{
		saved = (char *)malloc(sizeof(char) * 1);
		saved[0] = '\0';
	}
	if (!saved || !buf)
		return (NULL);
	str = malloc_join(saved, buf);
	while (saved[i])
	{
		str[i] = saved[i];
		i++;
	}
	while (buf[j])
		str[i++] = buf[j++];
	str[i] = '\0';
	free(saved);
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)s + i);
	return (NULL);
}

size_t	ft_strlen(const char *theString)
{
	int	i;

	i = 0;
	while (theString[i])
		i++;
	return (i);
}
