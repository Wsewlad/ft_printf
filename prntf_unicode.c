/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prntf_unicode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <vfil@student.unit.ua>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 17:16:53 by vfil              #+#    #+#             */
/*   Updated: 2018/01/25 17:16:55 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	convert_unichr(t_pfbuf **res, t_spec_elem spec, va_list ap)
{
	if (spec.cletter)
		get_symbol(res, va_arg(ap, unsigned int));
}

int 	count_bytes(unsigned int n)
{
	int bits;
	int bytes;

	bits = 0;
	bytes = 0;
	while (n)
	{
		n /= 2;
		bits++;
	}
	if (bits <= 7)
		bytes = 1;
	else if (bits <= 11)
		bytes = 2;
	else if (bits <= 16)
		bytes = 3;
	else if (bits <= 21)
		bytes = 4;
	return (bytes);
}

static void	push_flags(t_pfbuf **res, unsigned int *unistr, int prec)
{
	int	i;

	i = 0;
	while(unistr[i] && prec)
	{
		get_symbol(res, unistr[i++]);
		prec--;
	}
}

void 	find_len(unsigned int *unistr, t_spec_elem spec, int *symb, int *bytes)
{
	*symb = 0;
	*bytes = 0;
	if (spec.precision != -1)
	{
		while (unistr[*symb] && *bytes <= spec.precision)
			*bytes += count_bytes(unistr[(*symb)++]);
		*symb = *bytes > spec.precision ? *symb - 1 : *symb;
	}
	else
	{
		while (unistr[*symb])
			*bytes += count_bytes(unistr[(*symb)++]);
	}
}

void	convert_unistr(t_pfbuf **res, t_spec_elem spec, va_list ap)
{
	unsigned int	*unistr;
	int				symb;
	int 			padd;
	int 			bytes;

	unistr = va_arg(ap, unsigned int *);
	if (!unistr)
		fill_buf_str(res, "(null)", spec);
	else
	{
		find_len(unistr, spec, &symb, &bytes);
		//printf("zero: %d, fwidth: %d, prec: %d\n", spec.flags.zero, spec.fwidth, spec.precision);
		padd = 0;
		if (spec.precision == -1 && spec.fwidth && printf("1\n"))
			padd = spec.fwidth - bytes;
		else if (bytes && !(spec.precision % bytes) && spec.fwidth && printf("2\n"))
			padd = spec.fwidth - symb;
		else if (spec.precision != -1 && spec.fwidth && printf("3\n"))
		{
			padd = (spec.fwidth - spec.precision);
			if (bytes && spec.precision > 0 && bytes % spec.precision && printf("4\n"))
				padd += bytes - spec.precision - 1;
		}
				//printf("padd: %d\n", padd);
		//printf("symb: %d, bytes: %d, padd: %d\n", symb, bytes, padd);
		if (!spec.flags.minus)
		{
			if (spec.flags.zero && spec.precision == 0 && !symb)
				push_padding(res, padd > 0 ? padd : 0, spec, 1);
			else
				push_padding(res, padd > 0 ? padd : 0, spec, 0);
			push_flags(res, unistr, symb);
		}
		else
		{
			push_flags(res, unistr, symb);
			push_padding(res, padd > 0 ? padd : 0, spec, 0);
		}
	}
}
