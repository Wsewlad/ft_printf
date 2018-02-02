/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lltoa_buf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <vfil@student.unit.ua>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 13:52:42 by vfil              #+#    #+#             */
/*   Updated: 2018/02/02 13:52:44 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	find_len(unsigned long long un, int min)
{
	int	len;

	len = min ? 1 : 0;
	if (un == 0)
		len++;
	while (un > 0)
	{
		un /= 10;
		len++;
	}
	return (len);
}

static void		push_numb(t_pfbuf **res, unsigned long long un, int len, int min)
{
	unsigned long long 	pow;

	pow = 1;
	while ((len--) - 1)
		pow *= 10;
	if (min)
		fill_buf_chr(res, '-');
	while (pow)
	{
		fill_buf_chr(res, (un / pow) + '0');
		un %= pow;
		pow /= 10;
	}
}

void		lltoa_buf(t_pfbuf **res, long long n, t_spec_elem spec)
{
	unsigned long long	i;
	unsigned long long	un;
	int					len;
	int					min;

	i = 1;
	min = 0;
	if (n < 0)
	{
		min = 1;
		un = -n;
	}
	else
		un = n;
	if (spec.cletter)
	{
		len = find_len(un, min);
		push_numb(res, un, len, min);
	}
	}