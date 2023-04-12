/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:24:25 by fbouchar          #+#    #+#             */
/*   Updated: 2023/01/18 15:16:12 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Itère sur la liste ’lst’ et applique la fonction ’f ’au contenu de 
chaque élément. Crée une nouvelle liste résultant des applications 
successives de ’f’. La fonction ’del’ est là pour détruire le contenu 
d’un élément si nécessaire.*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*anew_lst;
	void	*temp;

	anew_lst = NULL;
	if (!lst || !f)
		return (NULL);
	while (lst)
	{
		temp = (*f)(lst->content);
		new_lst = ft_lstnew(temp);
		if (new_lst == NULL)
		{
			free(temp);
			ft_lstclear(&anew_lst, del);
			break ;
		}
		ft_lstadd_back(&anew_lst, new_lst);
		lst = lst->next;
	}
	return (anew_lst);
}
