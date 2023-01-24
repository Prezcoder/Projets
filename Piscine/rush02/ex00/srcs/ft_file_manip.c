/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_manip.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 09:17:19 by francoma          #+#    #+#             */
/*   Updated: 2022/12/11 14:39:53 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

char	*init_empty_str(void)
{
	char	*dest;

	dest = malloc(sizeof(*dest));
	if (!dest)
		return (NULL);
	*dest = '\0';
	return (dest);
}

char	*append_buffer(char *str, char *buff, int buff_size)
{
	char	*dest;
	int		i;
	int		j;
	int		str_size;

	str_size = ft_strlen(str);
	dest = malloc(sizeof(*dest) * (str_size + buff_size + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (i < str_size)
	{
		dest[i] = str[i];
		i++;
	}
	j = 0;
	while (j < buff_size)
	{
		dest[i + j] = buff[j];
		j++;
	}
	dest[i + j] = '\0';
	free(str);
	return (dest);
}

char	*get_dict_str(char	*dict_p, int *dict_error)
{
	int		fd;
	char	*dict_str;
	char	buff[128];
	int		rc;

	fd = open(dict_p, O_RDONLY);
	if (fd < 0)
		*dict_error = 1;
	dict_str = init_empty_str();
	if (!dict_str || fd < 0)
		return (NULL);
	rc = 1;
	while (rc > 0)
	{
		rc = read(fd, buff, 128);
		if (rc)
		{
			dict_str = append_buffer(dict_str, buff, rc);
			if (!dict_str)
				return (NULL);
		}
	}
	close(fd);
	return (dict_str);
}

char	*ft_read_std_entry(void)
{
	char	buff[16];
	int		rc;
	char	*nb_str;

	nb_str = init_empty_str();
	if (!nb_str)
		return (NULL);
	rc = 1;
	while (rc > 0)
	{
		rc = read(0, buff, 16);
		if (rc)
		{
			nb_str = append_buffer(nb_str, buff, rc);
			if (!nb_str)
				return (NULL);
		}
	}
	return (nb_str);
}
