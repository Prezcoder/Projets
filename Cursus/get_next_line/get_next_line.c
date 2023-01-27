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

	i = ft_strlen(str);
	printf("%d\n", i);
	j = ft_strlen(temp);
	printf("%d\n\n", j);
	k = i;
	i = 0;
	j = 0;
	while (i <= k)
	{
		temp[j++] = str[i++];
	}
	l = ft_strchr(str, '\n');
	if (l > 0)
	{
		i = 0;
		temp[i++] = str[l++];
	}
	
	// while (j == i)
	// {
	// 	j = 0;
	// 	while (temp[j])
	// 	{
	// 		dest[i++] = temp[j++];
	// 	}
	// 	break;
	// }
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
	if (!str)
		return (NULL);
	temp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!temp)
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
