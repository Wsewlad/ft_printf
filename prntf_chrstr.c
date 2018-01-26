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

void	test(char **str, t_spec_elem spec, va_list ap)
{
	t_conversions	cl;

	if ((cl.s = va_arg(ap, char *)) && spec.cletter)
		ft_strjoin_free(str, "_test_");
}

void	convert_chr(char **str, t_spec_elem spec, va_list ap)
{
	t_conversions	cl;

	if (ft_strcmp(spec.smod, "l"))
		convert_unichr(str, spec, ap);
	else
	{
		cl.c = (char)va_arg(ap, int);
		ft_chrjoin_free(str, cl.c);
	}
}

void	convert_str(char **str, t_spec_elem spec, va_list ap)
{
	t_conversions	cl;

	if (ft_strcmp(spec.smod, "l"))
		convert_unistr(str, spec, ap);
	else
	{
		cl.s = va_arg(ap, char*);
		if (cl.s == NULL)
			cl.s = "(null)";
		ft_strjoin_free(str, cl.s);
	}
}

void	convert_ptr(char **str, t_spec_elem spec, va_list ap)
{
	t_conversions	cl;
	char 			*buf;

	if (spec.cletter)
	{
		cl.ld = va_arg(ap, long int);
		ft_strjoin_free(str, "0x");
		ft_strjoin_free(str, buf = ft_llitoa_base(cl.ld, 16, 0));
		ft_strdel(&buf);
	}
}

void	convert_prcnt(char **str, t_spec_elem spec, va_list ap)
{
	t_conversions	cl;

	if (spec.cletter && ap)
	{
		cl.c = '%';
		ft_chrjoin_free(str, cl.c);
	}
}