/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 17:12:40 by tbayet            #+#    #+#             */
/*   Updated: 2016/03/06 17:21:54 by tbayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putstrn(char *str, int n)
{
	int	len;

	if (str)
	{
		len = ft_strlen(str);
		if (n >= len)
		{
			ft_putstr(str);
			while (n > len)
			{
				ft_putchar(' ');
				n--;
			}
		}
		else
			write(1, str, n);
	}
}
