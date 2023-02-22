/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 10:17:30 by fbouchar          #+#    #+#             */
/*   Updated: 2023/01/16 10:53:47 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Écrit le caractère ’c’ sur le descripteur de
fichier donné.*/
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
