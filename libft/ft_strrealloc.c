/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrealloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 10:19:44 by tbayet            #+#    #+#             */
/*   Updated: 2016/02/12 15:38:28 by tbayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	*ft_fillzero(char *str, int len)
{
	int	i;

	i = 0;
	while (i <= len)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}

char		*ft_strrealloc(char *str, int len)
{
	char	*res;
	int		plen;

	if (!str)
	{
		if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		str = ft_fillzero(str, len);
		return (str);
	}
	plen = ft_strlen(str);
	if (!(res = (char*)malloc(sizeof(char) * (plen + len + 1))))
		return (NULL);
	res = ft_fillzero(res, plen + len);
	res = ft_strcpy(res, str);
	free(str);
	return (res);
}
