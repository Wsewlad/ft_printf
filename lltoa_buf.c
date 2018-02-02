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

static int	find_len(unsigned long long un)
{
	int	len;

	len = 0;
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
	unsigned long long	un;
	int					len;
	int					min;
	int 				prec;
	int 				padd;

	min = 0;
	if (n < 0)
	{
		min = 1;
		un = -n;
	}
	else
		un = n;
	len = find_len(un);
	prec = (spec.precision > len - 1) ? spec.precision - len : 0;
//	printf("prec1: %d\n", prec);
	prec = (spec.flags.zero && spec.fwidth > len + prec && spec.precision == -1)
		   ? prec + (spec.fwidth - (len + prec)) : prec;
	//printf("prec2: %d\n", prec);
	n = (spec.flags.plus || spec.flags.space || min) ? 1 : 0;
	prec = (spec.flags.zero && n) ? prec - 1 : prec;
	//printf("prec3: %d\n", prec);
	padd = (spec.fwidth > len + prec) ? (spec.fwidth -
			(len + prec + n)) : 0;
	//printf("padd: %d\n", padd);
	if (!spec.flags.minus)
	{
		push_padding(res, padd, spec, 0);
		if (spec.flags.plus && !min)
			fill_buf_chr(res, '+');
		if (spec.flags.space && !spec.flags.plus && !min)
			fill_buf_chr(res, ' ');
		if (min)
		{
			fill_buf_chr(res, '-');
			min = 0;
		}
		push_padding(res, prec, spec, 1);
		if (spec.precision != 0 && un)
			push_numb(res, un, len, min);
	}
	else
	{
		if (spec.flags.plus && !min)
			fill_buf_chr(res, '+');
		if (spec.flags.space && !spec.flags.plus && !min)
			fill_buf_chr(res, ' ');
		if (spec.precision != -1 && min)
		{
			fill_buf_chr(res, '-');
			min = 0;
		}
		push_padding(res, prec, spec, 1);
		if (spec.precision != 0 && un)
			push_numb(res, un, len, min);
		push_padding(res, padd, spec, 0);
	}
}