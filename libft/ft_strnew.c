/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 13:55:01 by tbayet            #+#    #+#             */
/*   Updated: 2015/12/12 14:53:14 by tbayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char			*s;
	size_t			cpt;

	cpt = 0;
	s = NULL;
	if (!(s = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (cpt <= size)
	{
		s[cpt] = '\0';
		cpt++;
	}
	return (s);
}
