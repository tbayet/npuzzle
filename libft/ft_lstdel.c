/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 19:29:02 by tbayet            #+#    #+#             */
/*   Updated: 2015/12/11 15:21:27 by tbayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	if (alst)
	{
		if (*alst && del)
		{
			if ((*alst)->next)
				ft_lstdel(&((*alst)->next), del);
			del((*alst)->content, (*alst)->content_size);
		}
		free(*alst);
		*alst = NULL;
	}
}
