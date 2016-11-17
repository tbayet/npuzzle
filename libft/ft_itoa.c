/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 13:36:45 by tbayet            #+#    #+#             */
/*   Updated: 2015/12/12 14:04:46 by tbayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*ft_itoastr(int n, int isneg)
{
	char	*res;
	int		i;
	int		len;

	i = n;
	len = 0;
	while (i != 0)
	{
		i /= 10;
		len++;
	}
	if (!(res = (char*)malloc(sizeof(char) * (len + 1 + isneg))))
		return (NULL);
	res[len + isneg] = '\0';
	while (n != 0)
	{
		len--;
		res[len + isneg] = n % 10 + 48;
		n /= 10;
	}
	return (res);
}

char		*ft_itoa(int n)
{
	int		isneg;
	char	*res;

	if (n == 0)
		return (ft_strdup("0"));
	isneg = 0;
	if (n < 0)
	{
		isneg = 1;
		if (n == -2147483648)
			return (ft_strdup("-2147483648"));
		n = 0 - n;
	}
	if (!(res = ft_itoastr(n, isneg)))
		return (NULL);
	if (isneg)
		res[0] = '-';
	return (res);
}
