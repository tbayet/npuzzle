/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 12:57:11 by tbayet            #+#    #+#             */
/*   Updated: 2015/12/07 09:47:11 by tbayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s)
{
	unsigned int		len;
	unsigned int		start;
	unsigned int		end;
	char				*res;

	if (!s)
		return (NULL);
	start = 0;
	while (s[start] != '\0' && (s[start] == ' '
				|| s[start] == '\n' || s[start] == '\t'))
		start++;
	len = ft_strlen(s);
	if (s[start] == '\0')
		return (ft_strdup(""));
	end = len - 1;
	while (s[end] == ' ' || s[end] == '\n' || s[end] == '\t')
		end--;
	res = ft_strsub(s, start, (end - start) + 1);
	return (res);
}
