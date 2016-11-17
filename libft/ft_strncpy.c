/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayet <tbayet@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:33:58 by tbayet            #+#    #+#             */
/*   Updated: 2015/12/04 10:50:47 by tbayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	unsigned int i;

	if (!dst || !src)
		return (NULL);
	i = 0;
	while ((src[i] != '\0') && (i < n))
	{
		dst[i] = src[i];
		i++;
	}
	if (i == n)
		i++;
	while (i <= n)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}
