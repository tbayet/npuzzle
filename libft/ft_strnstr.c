/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 09:30:43 by tbayet            #+#    #+#             */
/*   Updated: 2015/12/04 10:53:20 by tbayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	int				j;
	char			*res;

	if (!s1 || !s2)
		return (NULL);
	if (s2[0] == '\0')
		return ((char*)s1);
	i = 0;
	res = NULL;
	while (s1[i] != '\0' && !res && i < n)
	{
		j = 0;
		if (s1[i] == s2[j])
		{
			while (s2[j] != '\0' && s1[i + j] == s2[j] && (i + j) < n)
				j++;
			if (s2[j] == '\0')
				res = (char*)&s1[i];
		}
		i++;
	}
	return (res);
}
