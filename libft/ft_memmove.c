/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 14:38:51 by tbayet            #+#    #+#             */
/*   Updated: 2015/12/04 10:30:09 by tbayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*temps;

	if (!dst || !src)
		return (NULL);
	temps = (char*)malloc(sizeof(char) * len);
	temps = ft_memcpy(temps, src, len);
	dst = ft_memcpy(dst, temps, len);
	free(temps);
	return (dst);
}
