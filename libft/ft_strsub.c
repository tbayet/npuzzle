/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 09:11:32 by tbayet            #+#    #+#             */
/*   Updated: 2016/03/22 01:15:02 by tbayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*res;
	unsigned int	i;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (NULL);
	i = 0;
	if (!(res = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i < len && s[i + start] != '\0')
	{
		res[i] = s[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
