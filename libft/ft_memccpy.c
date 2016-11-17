/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 14:25:09 by tbayet            #+#    #+#             */
/*   Updated: 2015/12/11 14:39:23 by tbayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned int	i;
	char			*tempd;
	char			*temps;

	if (!dst)
		return (NULL);
	if (!src)
		return (dst);
	tempd = (char*)dst;
	temps = (char*)src;
	i = 0;
	while (i < n)
	{
		tempd[i] = temps[i];
		if (temps[i] == c)
			return (dst + (i + 1));
		i++;
	}
	return (NULL);
}
