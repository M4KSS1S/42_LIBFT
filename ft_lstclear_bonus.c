/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaksiss <smaksiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 15:49:43 by smaksiss          #+#    #+#             */
/*   Updated: 2024/10/30 11:26:00 by smaksiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*head;
	t_list	*new;

	if (!lst || !del)
		return ;
	head = *lst;
	while (head)
	{
		new = head->next;
		del(head->content);
		free(head);
		head = new;
	}
	*lst = NULL;
}
