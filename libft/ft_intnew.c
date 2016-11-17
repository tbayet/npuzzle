/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 17:08:34 by tbayet            #+#    #+#             */
/*   Updated: 2016/03/06 17:10:43 by tbayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	*ft_intnew(int len)
{
	int	*res;

	if (!(res = (int*)malloc(sizeof(int) * (len + 1))))
		return (NULL);
	while (len)
	{
		res[len] = 0;
		len--;
	}
	return (res);
}
