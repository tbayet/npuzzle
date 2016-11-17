/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 14:21:46 by tbayet            #+#    #+#             */
/*   Updated: 2015/12/11 14:19:06 by tbayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*tempd;
	char	*temps;

	if (!dst)
		return (NULL);
	if (!src)
		return (dst);
	tempd = (char*)dst;
	temps = (char*)src;
	while (n > 0)
	{
		tempd[n - 1] = temps[n - 1];
		n--;
	}
	return (dst);
}
