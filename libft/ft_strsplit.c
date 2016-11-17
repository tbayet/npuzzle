/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 13:12:04 by tbayet            #+#    #+#             */
/*   Updated: 2016/03/22 01:23:40 by tbayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	**ft_strsplitstr(char **res, char const *s, char c)
{
	int	i;
	int	k;
	int	j;

	i = 0;
	k = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			j = 0;
			while (s[i + j] != c && s[i + j] != '\0')
				j++;
			if (!(res[k] = ft_strsub(s, (unsigned int)i, (unsigned int)j)))
				return (NULL);
			i += j;
			k++;
		}
		else
			i++;
	}
	res[k] = NULL;
	return (res);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**res;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	i = 1;
	j = 0;
	while (s[i - 1] != '\0')
	{
		if ((s[i] == c || s[i] == '\0') && s[i - 1] != c)
			j++;
		i++;
	}
	if (!(res = (char**)malloc(sizeof(char*) * (j + 1))))
		return (NULL);
	if (!(res = ft_strsplitstr(res, s, c)))
		return (NULL);
	return (res);
}
