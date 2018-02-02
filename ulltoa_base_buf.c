/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulltoa_base_buf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <vfil@student.unit.ua>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 13:03:44 by vfil              #+#    #+#             */
/*   Updated: 2018/02/02 13:03:45 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libftprintf.h"

static int	find_len(unsigned long long un, int base)
{
	int	len;

	len = 0;
	if (un == 0)
		len++;
	while (un > 0)
	{
		un /= (unsigned long long)base;
		len++;
	}
	return (len);
}

static void		push_unumb(t_pfbuf **res, int base, unsigned long long un,
					  int caps)
{
	unsigned long long 	pow;
	char 				ltr[24] = "0123456789abcdefABCDEF";
	int 				len;

	len = find_len(un, base);
	pow = 1;
	while ((len--) - 1)
		pow *= base;
	while (pow)
	{
		fill_buf_chr(res, (caps && (un / pow) > 9) ?
						  ltr[(un / pow) + 6] : ltr[un / pow]);
		un %= pow;
		pow /= base;
	}
}

void		ulltoa_base_buf(t_pfbuf **res, unsigned long long un,
							int *base_caps, t_spec_elem spec)
{
	int	len;

	if (spec.cletter)
		len = find_len(un, base_caps[0]);
	push_unumb(res, base_caps[0], un, base_caps[1]);
}

