/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 13:55:01 by tbayet            #+#    #+#             */
/*   Updated: 2015/12/12 13:37:34 by tbayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*res;
	int		cpt;

	if (!s || !f)
		return (NULL);
	cpt = 0;
	if (!(res = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	while (s[cpt] != '\0')
	{
		res[cpt] = f(cpt, s[cpt]);
		cpt++;
	}
	res[cpt] = '\0';
	return (res);
}
