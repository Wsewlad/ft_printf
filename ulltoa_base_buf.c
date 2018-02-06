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

int	find_ulen(unsigned long long un, int base)
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

void		push_unumb(t_pfbuf **res, int base, unsigned long long un,
                       int caps)
{
	unsigned long long 	pow;
	char 				ltr[24] = "0123456789abcdefABCDEF";
	int 				len;

	len = find_ulen(un, base);
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
    int min;
    int	prec;
    int	padd;

	len = (!un && spec.precision == 0 && !spec.flags.hash) ? 0 : \
    find_ulen(un, base_caps[0]);
    min = 0;
    prec = min;
    spec.flags.hash = (spec.flags.hash && !un) ? -1 : spec.flags.hash;
    spec.flags.hash = (spec.flags.hash && !un && (spec.cletter == 'x' \
 || spec.cletter == 'X')) ? 0 : spec.flags.hash;
    culc_prec_padd(&prec, &padd, len, spec);
    if (!spec.flags.minus)
    {
        push_padding(res, padd > 0 ? padd : 0, spec, 0);
        push_prec_flags(res, spec, &min, prec);
        if (spec.precision == 0 && spec.flags.hash != -1 && !un)
            return ;
        push_unumb(res, base_caps[0], un, base_caps[1]);
        return ;
    }
    push_prec_flags(res, spec, &min, prec);
    if (spec.precision == 0 && spec.flags.hash != -1 && !un)
        return ;
    push_unumb(res, base_caps[0], un, base_caps[1]);
    push_padding(res, padd > 0 ? padd : 0, spec, 0);
}

