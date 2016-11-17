/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 16:51:06 by tbayet            #+#    #+#             */
/*   Updated: 2016/03/17 18:58:46 by tbayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	**ft_tabdup(char **tab)
{
	char	**res;
	int		i;

	if (!(res = (char**)malloc(sizeof(char*) * (ft_tablen(tab) + 1))))
		return (NULL);
	i = 0;
	while (tab[i])
	{
		if (!(res[i] = ft_strdup(tab[i])))
		{
			ft_deltab(res);
			return (NULL);
		}
		i++;
	}
	res[i] = NULL;
	return (res);
}
