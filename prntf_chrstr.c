/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prntf_chrstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <vfil@student.unit.ua>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 15:20:08 by vfil              #+#    #+#             */
/*   Updated: 2018/01/17 15:20:10 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	test(t_pfbuf **res, t_spec_elem spec, va_list ap)
{
	t_conversions	cl;

	if ((cl.s = va_arg(ap, char *)) && spec.cletter)
		fill_buf_str(res, "_test_", spec);
}

void	convert_chr(t_pfbuf **res, t_spec_elem spec, va_list ap)
{
	t_conversions	cl;

	if (ft_strcmp(spec.smod, "l") == 0)
		convert_unichr(res, spec, ap);
	else
	{
		cl.c = (char)va_arg(ap, int);
		if (!spec.flags.minus)
		{
			fill_padding(res, spec.fwidth - 1, spec);
			fill_buf_chr(res, cl.c);
		}
		else
		{
			fill_buf_chr(res, cl.c);
			fill_padding(res, spec.fwidth - 1, spec);
		}
	}
}

void	convert_str(t_pfbuf **res, t_spec_elem spec, va_list ap)
{
	t_conversions	cl;

	if (ft_strcmp(spec.smod, "l") == 0)
		convert_unistr(res, spec, ap);
	else
	{
		cl.s = va_arg(ap, char*);
		if (cl.s == NULL)
			cl.s = "(null)";
		fill_buf_str(res, cl.s, spec);
	}
}

void	convert_ptr(t_pfbuf **res, t_spec_elem spec, va_list ap)
{
	t_conversions	cl;
	char 			*buf;

	if (spec.cletter)
	{
		cl.ld = va_arg(ap, long int);
		fill_buf_str(res, "0x", spec);
		fill_buf_str(res, buf = ft_llitoa_base(cl.ld, 16, 0), spec);
		ft_strdel(&buf);
	}
}

void	convert_prcnt(t_pfbuf **res, t_spec_elem spec, va_list ap)
{
	t_conversions	cl;

	if (spec.cletter && ap)
	{
		cl.c = '%';
		fill_buf_chr(res, cl.c);
	}
}