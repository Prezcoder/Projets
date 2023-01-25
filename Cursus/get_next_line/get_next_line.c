/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:38:43 by fbouchar          #+#    #+#             */
/*   Updated: 2023/01/25 15:45:47 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_select(char *buf)
{
	int		i;
	int		j;
	char	*dest;

	i = 0;
	while (buf[i] != '\n')
		i++;
	dest = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!dest)
		return (NULL);
	j = 0;
	while (buf[i])
		dest[j++] = buf[i++];
	dest[j] = 0;
	return (dest);
}

char	*get_next_line(int fd)
{
	int	j;
	int	i;
	char	*temp2;
	int			bytes;
	static char		*temp;
	char		buf[BUFFER_SIZE + 1];
	 char	*str = NULL;

	if (fd < 0)
		return (NULL);
	str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!str)
			return (NULL);
	bytes = 0;
	while (bytes >= 0 && !ft_strchr(str, '\n'))
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes == 0)
			return (NULL);
		buf[bytes] = '\0';
		str = ft_strjoin(str, buf);
		if (ft_strchr(str, '\n'))
			break;
	}
	// temp = str;
	temp = ft_select(str);
	j = ft_strlen(temp);
	printf("%d", j);
	i = ft_strlen(str);
	
	// free(temp);
	// if(bytes == 0 && (str[0]) == 0)
	// {
	// 	free (str);
	// 	str = NULL;
	// }
	return (&str[j-i]);
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
