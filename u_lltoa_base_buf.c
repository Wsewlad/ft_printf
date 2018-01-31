/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_lltoa_base_buf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <vfil@student.unit.ua>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 20:02:40 by vfil              #+#    #+#             */
/*   Updated: 2018/01/31 20:02:42 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	find_len(unsigned long long un, int base, int is_neg)
{
	int	len;

	len = (is_neg == 1 || is_neg == 2) ? 1 : 0;
	if (un == 0)
		len++;
	while (un > 0)
	{
		un /= (unsigned long long)base;
		len++;
	}
	return (len);
}

/*
 * if "neg_caps == 1" (is_neg == 1) else if "neg_caps == 2" (is_neg == 1
 * && caps == 1)
 */

void		push_numb(t_pfbuf **res, int base, unsigned long long un,
					  int is_neg_caps)
{
	unsigned long long 	pow;
	char 				ltr[24] = "0123456789abcdefABCDEF";
	int 				len;

	len = find_len(un, base, is_neg_caps);
	pow = 1;
	while ((len--) - 1)
		pow *= base;
	if (is_neg_caps == 1 || is_neg_caps == 2)
		fill_buf_chr(res, '-');
	while (pow)
	{
		fill_buf_chr(res, ((is_neg_caps == 2 || is_neg_caps == -1) &&
				((un / pow) > 9)) ? ltr[(un / pow + 6)] : ltr[un / pow]);
		un %= pow;
		pow /= base;
	}
}

void		lltoa_base_buf(t_pfbuf **res, long long ln, int base, int caps)
{
	int					len;
	int					is_neg_caps;
	unsigned long long	un;

	is_neg_caps = 0;
	if (ln < 0)
	{
		un = -ln;
		if (base == 10)
			is_neg_caps = 1;
	}
	else
		un = ln;
	if (caps && is_neg_caps)
		is_neg_caps = 2;
	if (caps && !is_neg_caps)
		is_neg_caps = -1;
	len = find_len(un, base, is_neg_caps);
	push_numb(res, base, un, is_neg_caps);
}
