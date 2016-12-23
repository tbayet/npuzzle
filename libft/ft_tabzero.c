/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabzero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 16:51:06 by tbayet            #+#    #+#             */
/*   Updated: 2016/03/22 01:23:10 by tbayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	**ft_tabzero(char **tab, int leni, int lenj)
{
	int	i;

	i = 0;
	while (i < leni)
		ft_bzero(tab[i++], lenj);
	return (tab);
}
