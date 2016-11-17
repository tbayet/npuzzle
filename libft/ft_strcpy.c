/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayet <tbayet@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:33:58 by tbayet            #+#    #+#             */
/*   Updated: 2015/12/11 14:37:43 by tbayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	int cpt;

	if (!dst)
		return (NULL);
	if (!src)
		return (dst);
	cpt = 0;
	while (src[cpt] != '\0')
	{
		dst[cpt] = src[cpt];
		cpt++;
	}
	dst[cpt] = '\0';
	return (dst);
}
