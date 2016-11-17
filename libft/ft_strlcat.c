/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:50:40 by tbayet            #+#    #+#             */
/*   Updated: 2015/12/12 14:09:59 by tbayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t			res;
	unsigned int	i;
	size_t			len;

	i = 0;
	res = 0;
	len = 0;
	while (dst[res] != '\0' && res < size)
		res++;
	while (src[len] != '\0')
		len++;
	while (src[i] != '\0' && (i + res) < size - 1)
	{
		dst[res + i] = src[i];
		i++;
	}
	if (size > res)
		dst[res + i] = '\0';
	res += len;
	return (res);
}
