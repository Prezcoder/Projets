/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:38:43 by fbouchar          #+#    #+#             */
/*   Updated: 2023/01/25 16:00:42 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_select(char *str, char *temp)
{
	int		i;
	int		j;
	int		k;
	int		l;

	k = ft_strlen(str);
	printf("%d\n", k);
	i = 0;
	j = 0;
	while (i <= k && (!ft_strchr(str, '\n')))
		temp[j++] = str[i++];
	l = ft_strchr(str, '\n');
	if ( l > 0)
	{
		while (l < k)
		{
			i = 0;
			l += 1;
			ft_memset(temp, 0, BUFFER_SIZE + 1);
			while (l < k)
				temp[i++] = str[l++];
		}
	}
	return (temp);
}

char	*get_next_line(int fd)
{
	int			bytes;
	static char	*temp;
	char		buf[BUFFER_SIZE + 1];
	char		*str;

	if (fd < 0)
		return (NULL);
	str = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	temp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!temp || !str)
		return (NULL);
	bytes = 1;
	while (bytes > 0)
	{	
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes == 0)
			return (NULL);
		buf[bytes] = '\0';
		str = ft_strjoin(temp, buf);
		temp = ft_select(str, temp);
		if (ft_strchr(buf, '\n'))
			break;
	}
	str = ft_strtrim(str, temp);
	return (str);
}
// &buf[ft_strchr(buf, '\n')]

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = (malloc(count * size));
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, count * size);
	return (ptr);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	if (!b)
		return (NULL);
	ptr = (unsigned char *)b;
	while (i < len)
	{
		ptr[i] = c;
		i++;
	}
	return (ptr);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*result;
	int			i;
	int			j;

	i = 0;
	j = ft_strlen(s1);
	if (!s1 || !set)
		return (NULL);
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (j > i && ft_strchr(set, s1[j - 1]))
		j--;
	result = malloc(sizeof(char) * (j - i) + 1);
	if (!result)
		return (NULL);
	ft_strlcpy(result, s1 + i, (j - i) + 1);
	return (result);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	if (!dst || !src)
		return (0);
	src_len = ft_strlen(src);
	if (!dstsize)
		return (src_len);
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize < src_len)
		dst[dstsize - 1] = '\0';
	else if (dstsize != 0)
		dst[i] = '\0';
	return (src_len);
}