/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorttab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 03:07:06 by tbayet            #+#    #+#             */
/*   Updated: 2016/01/25 04:47:07 by tbayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_sorttab(char **tab)
{
	int		i;
	int		j;
	char	*tmp;

	j = ft_tablen(tab);
	while (j > 0)
	{
		i = 1;
		while (tab[i])
		{
			if (ft_strcmp(tab[i - 1], tab[i]) > 0)
			{
				tmp = tab[i];
				tab[i] = tab[i - 1];
				tab[i - 1] = tmp;
			}
			i++;
		}
		j--;
	}
	return (tab);
}
