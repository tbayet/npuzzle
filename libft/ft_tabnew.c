/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 16:51:06 by tbayet            #+#    #+#             */
/*   Updated: 2016/03/22 01:23:10 by tbayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	**ft_tabnew(int leni, int lenj)
{
	int	i;
	char	**tab;

	if (!(tab = (char**)malloc(sizeof(char*) * (leni + 1))))
		return (NULL);
	i = 0;
	while (i < leni)
		tab[i++] = NULL;
	i = 0;
	while (i < leni)
	{
		if (!(tab[i++] = ft_strnew(lenj)))
			return (ft_deltab(tab));
	}
	return (tab);
}
