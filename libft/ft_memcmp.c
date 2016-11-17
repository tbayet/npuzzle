/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 14:43:02 by tbayet            #+#    #+#             */
/*   Updated: 2015/12/04 11:01:27 by tbayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*temp1;
	unsigned char	*temp2;

	if (n == 0)
		return (0);
	temp1 = (unsigned char*)s1;
	temp2 = (unsigned char*)s2;
	i = 0;
	while ((temp1 && temp2) && (temp1[i] == temp2[i]) && (i < n))
		i++;
	if (i == n)
		i--;
	return ((int)temp1[i] - (int)temp2[i]);
}
