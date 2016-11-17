/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 19:22:42 by tbayet            #+#    #+#             */
/*   Updated: 2015/12/04 11:30:09 by tbayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*keep;
	t_list	*new;

	if (lst)
	{
		if (f)
		{
			new = f(ft_lstnew(lst->content, lst->content_size));
			keep = new;
			while (lst->next)
			{
				lst = lst->next;
				new->next = f(ft_lstnew(lst->content, lst->content_size));
				new = new->next;
			}
			return (keep);
		}
		else
			return (lst);
	}
	else
		return (NULL);
}
