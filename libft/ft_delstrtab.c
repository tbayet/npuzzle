/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delstrtab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 02:48:11 by tbayet            #+#    #+#             */
/*   Updated: 2016/03/18 14:55:53 by tbayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		**ft_delstrtab(char **tab, int i)
{
	if (tab && *tab && tab[i])
	{
		while (tab[i + 1])
		{
			free(tab[i]);
			if (!(tab[i] = ft_strdup(tab[i + 1])))
				return (NULL);
			i++;
		}
		free(tab[i]);
		tab[i] = NULL;
	}
	return (tab);
}
