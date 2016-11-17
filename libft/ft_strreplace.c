/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 09:51:11 by tbayet            #+#    #+#             */
/*   Updated: 2015/12/07 10:15:33 by tbayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strreplace(char *str, char c1, char c2)
{
	int	i;
	int	len;

	if (!str)
		return (NULL);
	if (!c1 || !c2)
		return (str);
	i = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		if (str[i] == c1)
			str[i] = c2;
		i++;
	}
	return (str);
}
