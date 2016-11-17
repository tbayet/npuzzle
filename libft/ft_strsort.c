/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 09:51:01 by tbayet            #+#    #+#             */
/*   Updated: 2015/12/07 10:17:05 by tbayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsort(char *str)
{
	int		i;
	int		len;
	int		j;
	char	tmp;

	i = 0;
	j = 0;
	len = ft_strlen(str);
	while (i < len - 1)
	{
		while (j < len - 1)
		{
			if (str[j] > str[j + 1])
			{
				tmp = str[j];
				str[j] = str[j + 1];
				str[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
	return (str);
}
