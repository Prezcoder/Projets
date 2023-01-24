/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_dict.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 14:01:45 by francoma          #+#    #+#             */
/*   Updated: 2022/12/11 12:36:11 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

char	*get_val(char *dict_str)
{
	char	*str;
	int		len;
	int		i;

	while (*dict_str >= '0' && *dict_str <= '9')
		dict_str++;
	while (is_space(*dict_str))
		dict_str++;
	dict_str++;
	while (is_space(*dict_str))
		dict_str++;
	len = ft_trim_space(dict_str);
	str = malloc(sizeof(*str) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = dict_str[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

t_dict_entry	*str_to_dict(char *dict_str, t_dict_entry	*dict)
{
	int				i;
	int				j;

	if (!ft_is_valid_dict_format(dict_str))
		return (dict);
	i = 0;
	j = 0;
	while (dict_str[i])
	{
		if ((i == 0 || dict_str[i - 1] == '\n')
			&& ft_is_useful_entry(dict_str + i, dict))
		{
			dict[j].key = ft_atoi(dict_str + i);
			dict[j].val = get_val(dict_str + i);
			if (!dict[j].val)
				return (NULL);
			j++;
		}
		i++;
	}
	dict[j].val = NULL;
	return (dict);
}

void	ft_sort_dict(t_dict_entry *dict)
{
	int				i;
	t_dict_entry	temp;
	int				swap;

	swap = 0;
	i = 0;
	while (dict[i].val)
	{
		if (i != 0 && dict[i - 1].key < dict[i].key)
		{
			temp = dict[i - 1];
			dict[i - 1] = dict[i];
			dict[i] = temp;
			swap = 1;
		}
		else
			i++;
	}
	if (swap)
		ft_sort_dict(dict);
}

t_dict_entry	*ft_init_dict(void)
{
	t_dict_entry	*dict;
	int				i;

	dict = malloc(sizeof(*dict) * (DICT_SIZE + 1));
	if (!dict)
		return (NULL);
	i = 0;
	while (i < DICT_SIZE)
		dict[i++].val = NULL;
	dict[i].val = NULL;
	return (dict);
}

t_dict_entry	*ft_parse_dict(char *dict_str, int	*dict_error)
{
	t_dict_entry	*dict;

	dict = ft_init_dict();
	if (!dict)
		return (NULL);
	dict = str_to_dict(dict_str, dict);
	if (!dict)
		return (NULL);
	*dict_error = !ft_dict_is_complete(dict);
	if (*dict_error)
		return (NULL);
	ft_sort_dict(dict);
	return (dict);
}
