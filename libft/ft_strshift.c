/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strshift.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 09:51:56 by tbayet            #+#    #+#             */
/*   Updated: 2015/12/07 10:16:52 by tbayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strshift(char *str, int nb)
{
	int		i;
	int		j;
	int		len;
	char	c;

	if (!str)
		return (NULL);
	i = 0;
	len = ft_strlen(str);
	while (i < nb)
	{
		j = 1;
		c = str[0];
		while (j + 1 < len)
		{
			str[j] = str[j + 1];
			j++;
		}
		str[j] = c;
		i++;
	}
	return (str);
}
