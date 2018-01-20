/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ulonglong.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <vfil@student.unit.ua>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 18:20:06 by vfil              #+#    #+#             */
/*   Updated: 2018/01/19 18:20:09 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_fill_arr(unsigned long long n, unsigned long long i, int len)
{
	unsigned long long	j;
	char				*str;

	j = 0;
	str = ft_strnew(len + 1);
	if (str == NULL)
		return (str);
	while (i > 0)
	{
		str[j] = n / i + '0';
		n %= i;
		i /= 10;
		j++;
	}
	str[j] = '\0';
	return (str);
}

char		*ft_itoa_ull(unsigned long long n)
{
	unsigned long long	i;
	int					len;

	i = 1;
	len = 0;
	while (n / i > 9)
	{
		i *= 10;
		len++;
	}
	return (ft_fill_arr(n, i, len));
}