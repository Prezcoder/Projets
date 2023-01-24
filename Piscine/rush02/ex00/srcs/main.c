/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 08:28:42 by francoma          #+#    #+#             */
/*   Updated: 2022/12/11 16:56:27 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

void	parse_args(int argc, char *argv[], char **dict_p, char **nb_str)
{
	if (argc == 1)
	{
		*dict_p = "numbers.dict";
		*nb_str = ft_read_std_entry();
	}
	else if (argc == 2)
	{
		*dict_p = "numbers.dict";
		*nb_str = argv[1];
	}
	else if (argc >= 3)
	{
		*dict_p = argv[1];
		*nb_str = argv[2];
	}
}

t_dict_entry	*dict_steps(char *dict_p, int *dict_error)
{
	char			*dict_str;
	t_dict_entry	*dict;

	dict_str = get_dict_str(dict_p, dict_error);
	if (!dict_str)
		return (NULL);
	if (!*dict_error)
		*dict_error = !ft_is_valid_dict_format(dict_str);
	dict = NULL;
	if (!*dict_error)
		dict = ft_parse_dict(dict_str, dict_error);
	free(dict_str);
	return (dict);
}

int	main(int argc, char *argv[])
{
	char			*dict_p;
	char			*nb_str;
	t_dict_entry	*dict;
	int				dict_error;

	parse_args(argc, argv, &dict_p, &nb_str);
	if (!ft_valid_unsigned_int(nb_str))
	{
		ft_putstr("Error");
		return (0);
	}
	dict_error = 0;
	dict = dict_steps(dict_p, &dict_error);
	if (dict_error)
		ft_putstr("Dict Error");
	else if (dict)
	{
		if (ft_strcmp(dict_p, "nombres.dict") == 0)
			spell_number_fr(ft_atoi(nb_str), dict);
		else
			spell_number(ft_atoi(nb_str), dict);
	}
	write(1, "\n", 1);
	free_dict(dict, argc == 1, nb_str);
	return (0);
}
