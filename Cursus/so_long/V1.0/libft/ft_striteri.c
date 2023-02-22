/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 09:22:47 by fbouchar          #+#    #+#             */
/*   Updated: 2023/01/16 10:54:28 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Applique la fonction ’f’ à chaque caractère de la chaîne de caractères 
transmise comme argument, et en passant son index comme premier argument.
Chaque caractère est transmis par adresse à ’f’ afin d’être modifié 
si nécessaire.*/
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		(*f)(i, (s + i));
		i++;
	}
}
