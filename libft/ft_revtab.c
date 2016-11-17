/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revtab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 03:16:53 by tbayet            #+#    #+#             */
/*   Updated: 2016/01/25 03:21:43 by tbayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_revtab(char **tab)
{
	char	*tmp;
	int		i;
	int		max;

	i = 0;
	max = ft_tablen(tab) - 1;
	while (i < max)
	{
		tmp = tab[i];
		tab[i] = tab[max];
		tab[max] = tmp;
		i++;
		max--;
	}
	return (tab);
}
