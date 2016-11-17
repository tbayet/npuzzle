/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelthis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 15:35:29 by tbayet            #+#    #+#             */
/*   Updated: 2016/02/12 16:14:23 by tbayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdelthis(t_list **lst, t_list *this)
{
	t_list	*tmp;
	t_list	*jump;

	if (lst && *lst && this)
	{
		tmp = *lst;
		if (tmp == this)
		{
			*lst = tmp->next;
			if (tmp->content)
				free(tmp->content);
			free(tmp);
		}
		else
		{
			while (tmp->next != this)
				tmp = tmp->next;
			jump = tmp->next->next;
			if (tmp->next->content)
				free(tmp->next->content);
			free(tmp->next);
			tmp->next = jump;
		}
	}
}
