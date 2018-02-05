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

static void	push_numb(t_pfbuf **res, unsigned long long un, int len, \
					int min)
{
	unsigned long long	pow;

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

void	culc_prec_padd(int *prec, int *padd, int len, t_spec_elem spec)
{
	int n;
	int min;

	min = *prec;
	*prec = (spec.precision > len - 1) ? spec.precision - len : 0;
	*prec = (spec.flags.zero && !spec.flags.minus && spec.fwidth > len + *prec && \
	spec.precision == -1) ? *prec + (spec.fwidth - (len + *prec)) : *prec;
	n = (spec.flags.plus || spec.flags.space || min) ? 1 : 0;
	*prec = (spec.flags.zero && n && !spec.flags.minus) ? *prec - 1 : *prec;
    *prec = (spec.flags.zero && spec.precision != -1 && min) ? *prec + 1 : *prec;
	*padd = (spec.fwidth > len + *prec) ? (spec.fwidth - (len + *prec + n)) : 0;
}

void	push_prec_flags(t_pfbuf **res, t_spec_elem spec, int *min, int prec)
{
	if (spec.flags.plus && !*min)
		fill_buf_chr(res, '+');
	if (spec.flags.space && !spec.flags.plus && !*min)
		fill_buf_chr(res, ' ');
	if (*min)
	{
		fill_buf_chr(res, '-');
		*min = 0;
	}
	push_padding(res, prec > 0 ? prec : 0, spec, 1);
}

void		lltoa_buf(t_pfbuf **res, long long n, t_spec_elem spec)
{
	unsigned long long	un;
	int					len;
	int					min;
	int					prec;
	int					padd;

	min = (n < 0) ? 1 : 0;
	un = (n < 0) ? -n : n;
	len = (!un && spec.precision == 0) ? 0 : find_len(un);
	prec = min;
	culc_prec_padd(&prec, &padd, len, spec);
	if (!spec.flags.minus)
	{
		push_padding(res, padd, spec, 0);
		push_prec_flags(res, spec, &min, prec);
		if (spec.precision == 0 && !un)
			return ;
		push_numb(res, un, len, min);
		return ;
	}
	push_prec_flags(res, spec, &min, prec);
	if (spec.precision == 0 && !un)
		return ;
	push_numb(res, un, len, min);
	push_padding(res, padd, spec, 0);
}
