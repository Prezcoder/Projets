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
	while (bytes > 0 && (!ft_strchr(buf, '\n')))
	{	
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes == 0)
			return (NULL);
		buf[bytes] = '\0';
		str = ft_strjoin(temp, buf);
		temp = ft_select(str, temp);
	}
	if (ft_strchr(buf, '\n'))
		str = ft_truncate(str);
	return (str);
}
// &buf[ft_strchr(buf, '\n')]
char	*ft_truncate(char *str)
{
	int i;
	int j;

	j = 0;
	i = ft_strchr(str, '\n');
	while (j != i)
		j++;
	str[j] = '\0';
	return (str);
}

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
