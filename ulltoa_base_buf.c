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

void	uculc_prec_padd(int *prec, int *padd, int len, t_spec_elem spec)
{
	int n;
	int min;

	min = *prec;
	*prec = (spec.precision > len - 1) ? spec.precision - len : 0;
	*prec = (spec.flags.zero && !spec.flags.minus && spec.fwidth > len + *prec && \
    spec.precision == -1) ? *prec + (spec.fwidth - (len + *prec)) : *prec;
	n = (spec.flags.plus || spec.flags.space || min || spec.flags.hash > 0) ? 1 : 0;
	*prec = (spec.flags.hash > 0 && spec.cletter != 'x' && spec.cletter != 'X') ? *prec - 1 : *prec;
	*prec = (spec.flags.zero && n && !spec.flags.minus) ? *prec - 1 : *prec;
	*prec = (spec.flags.zero && spec.precision != -1 && min) ? *prec + 1 : *prec;
	*padd = (spec.fwidth > len + *prec) ? (spec.fwidth - (len + *prec + n)) : 0;
	if (spec.flags.hash > 0 )
		*padd = (spec.cletter == 'x' || spec.cletter == 'X') ? *padd - 2 : *padd - 1;

}

void	push_prec_flags(t_pfbuf **res, t_spec_elem spec, int *min, int prec)
{
	if (spec.cletter == 'd' || spec.cletter == 'D' || spec.cletter == 'i')
	{
		if (spec.flags.plus && !*min)
			fill_buf_chr(res, '+');
		if (spec.flags.space && !spec.flags.plus && !*min)
			fill_buf_chr(res, ' ');
	}
	if (*min)
	{
		fill_buf_chr(res, '-');
		*min = 0;
	}
	if (spec.flags.hash > 0)
	{
		if (spec.cletter == 'o' || spec.cletter == 'O')
			fill_buf_chr(res, '0');
		else if (spec.cletter == 'x' || spec.cletter == 'X')
		{
			fill_buf_chr(res, '0');
			fill_buf_chr(res, (spec.cletter == 'x') ? 'x' : 'X');
		}
	}
	push_padding(res, prec > 0 ? prec : 0, spec, 1);
}

void		ulltoa_base_buf(t_pfbuf **res, unsigned long long un,
							int *base_caps, t_spec_elem spec)
{
	t_var	v;

	v.un = un;
	v.len = (!v.un && spec.precision == 0 && !spec.flags.hash) ? 0 : \
    find_ulen(v.un, base_caps[0]);
	v.min = 0;
	v.prec = v.min;
    spec.flags.hash = (spec.flags.hash && !v.un) ? -1 : spec.flags.hash;
    spec.flags.hash = (spec.flags.hash && !v.un && (spec.cletter == 'x' \
|| spec.cletter == 'X')) ? 0 : spec.flags.hash;
    uculc_prec_padd(&v.prec, &v.padd, v.len, spec);
    if (!spec.flags.minus)
    {
        push_padding(res, v.padd > 0 ? v.padd : 0, spec, 0);
        push_prec_flags(res, spec, &v.min, v.prec);
        if (spec.precision == 0 && spec.flags.hash != -1 && !v.un)
            return ;
        push_unumb(res, base_caps[0], v.un, base_caps[1]);
        return ;
    }
    push_prec_flags(res, spec, &v.min, v.prec);
    if (spec.precision == 0 && spec.flags.hash != -1 && !v.un)
        return ;
    push_unumb(res, base_caps[0], v.un, base_caps[1]);
    push_padding(res, v.padd > 0 ? v.padd : 0, spec, 0);
}

