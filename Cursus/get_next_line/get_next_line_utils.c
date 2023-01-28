/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:39:05 by fbouchar          #+#    #+#             */
/*   Updated: 2023/01/25 14:55:33 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	if (s[i] == (char)c)
		return (i);
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	int		size_s1;
	int		size_s2;

	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	if (!s1 || !s2)
		return (NULL);
	ptr = (char *)malloc(sizeof(char) * (size_s1 + size_s2) + 1);
	if (!ptr)
		return (NULL);
	ft_memmove(ptr, s1, size_s1);
	ft_memmove(ptr + size_s1, s2, size_s2);
	ptr[size_s1 + size_s2] = '\0';
	return (ptr);
}

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

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned int	i;
	unsigned char	*dest;
	unsigned char	*source;

	source = (unsigned char *)src;
	dest = (unsigned char *)dst;
	if (!dst || !src)
		return (NULL);
	if (dest < source)
		return (ft_memcpy(dest, src, len));
	else
	{
		i = len;
		while (i > 0)
		{
			dest[i - 1] = source[i - 1];
			i--;
		}
	}
	return (dest);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}