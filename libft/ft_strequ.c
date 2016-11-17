/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 13:55:01 by tbayet            #+#    #+#             */
/*   Updated: 2015/12/04 11:13:46 by tbayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	int	cpt;
	int	egal;

	if (s1 && s2)
	{
		cpt = 0;
		egal = 1;
		while (egal && cpt != -1)
		{
			if (s1[cpt] == '\0' && s2[cpt] == '\0')
				cpt = -2;
			else if (s1[cpt] != s2[cpt])
				egal = 0;
			cpt++;
		}
	}
	else
		egal = 0;
	return (egal);
}
