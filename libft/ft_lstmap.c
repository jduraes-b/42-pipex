/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:48:00 by jduraes-          #+#    #+#             */
/*   Updated: 2023/05/11 16:50:39 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*no;

	newlist = NULL;
	if (lst && f && del)
	{
		while (lst)
		{
			no = ft_lstnew(f(lst->content));
			lst = lst->next;
			if (!no)
			{
				ft_lstclear(&newlist, del);
				return (NULL);
			}
			ft_lstadd_back(&newlist, no);
		}
	}
	return (newlist);
}
