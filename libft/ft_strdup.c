/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayet <tbayet@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:01:57 by tbayet            #+#    #+#             */
/*   Updated: 2015/12/12 13:53:02 by tbayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	int		cpt;
	char	*s2;

	if (!s1)
		return (NULL);
	cpt = 0;
	if (!(s2 = (char*)malloc(sizeof(char) * (ft_strlen(s1) + 1))))
		return (NULL);
	while (s1[cpt] != '\0')
	{
		s2[cpt] = s1[cpt];
		cpt++;
	}
	s2[cpt] = '\0';
	return (s2);
}
