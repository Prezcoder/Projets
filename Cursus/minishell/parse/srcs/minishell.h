/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:07:05 by fbouchar          #+#    #+#             */
/*   Updated: 2023/05/18 14:37:25 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include "libft/libft.h"
#include <readline/readline.h>
#include <readline/history.h>

typedef	struct	s_ltkn
{
	char			*token;
	struct s_ltkn	*next;
}				t_ltkn;

typedef	struct	s_lcmd
{
	char			*cmdpath;
	char			**argv;
	int				builtin;
	struct s_lcmd	*next;
}				t_lcmd;

typedef	struct	s_data
{
	t_ltkn	ltkn;
	t_lcmd	lcmd;
	char	**path;
}				t_data;

#endif