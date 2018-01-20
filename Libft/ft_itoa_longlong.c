/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_longlong.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <vfil@student.unit.ua>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 18:04:02 by vfil              #+#    #+#             */
/*   Updated: 2018/01/18 18:04:04 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_fill_arr(long long n, long long i, int len, int min)
{
	long long	j;
	char		*str;

	j = 0;
	str = ft_strnew(len + 1);
	if (str == NULL)
		return (str);
	if (min)
		str[j++] = '-';
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

char		*ft_itoa_ll(long long n)
{
	long long int	i;
	int				len;
	int				min;

	i = 1;
	len = 0;
	min = 0;
	if (n < 0)
	{
		min = 1;
		n *= -1;
		len++;
	}
	while (n / i > 9)
	{
		i *= 10;
		len++;
	}
	return (ft_fill_arr(n, i, len, min));
}