/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplitone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 13:12:04 by tbayet            #+#    #+#             */
/*   Updated: 2016/04/04 18:14:48 by tbayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	**ft_strsplitstr(char **res, char const *s, char c)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	if (!(res[0] = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		res[0][i] = s[i];
		i++;
	}
	res[0][i] = '\0';
	i++;
	k = ft_strlen(s) - i;
	if (!(res[1] = (char*)malloc(sizeof(char) * (k + 1))))
		return (NULL);
	k = 0;
	while (s[i])
		res[1][k++] = s[i++];
	res[1][k] = '\0';
	return (res);
}

char		**ft_strsplitone(char const *s, char c)
{
	char	**res;

	if (!s)
		return (NULL);
	if (!ft_charstr((char*)s, c))
		return (NULL);
	if (!(res = (char**)malloc(sizeof(char*) * (3))))
		return (NULL);
	res[2] = NULL;
	if (!(res = ft_strsplitstr(res, s, c)))
		return (NULL);
	return (res);
}
