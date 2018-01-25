/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prntf_numb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <vfil@student.unit.ua>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 17:40:38 by vfil              #+#    #+#             */
/*   Updated: 2018/01/12 17:40:43 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	convert_diD(char **str, t_spec_elem spec, va_list ap)
{
	char			*buf;
	t_conversions	cl;

	buf = NULL;
	if (spec.cletter == 'D')
		ft_strjoin_free(str, buf = ft_llitoa(cl.ld = va_arg(ap, long)));
	else if (!ft_strcmp(spec.smod, "l"))
		ft_strjoin_free(str, buf = ft_llitoa(cl.ld = va_arg(ap, long)));
	else if (!ft_strcmp(spec.smod, "ll"))
		ft_strjoin_free(str, buf = ft_llitoa(cl.lld = va_arg(ap, long \
 long)));
	else if (!ft_strcmp(spec.smod, "h"))
		ft_strjoin_free(str, buf = ft_itoa(cl.hd = va_arg(ap, int)));
	else if (!ft_strcmp(spec.smod, "hh"))
		ft_strjoin_free(str, buf = ft_itoa(cl.hhd = va_arg(ap, int)));
	else if (!ft_strcmp(spec.smod, "j"))
		ft_strjoin_free(str, buf = ft_llitoa(cl.jd = va_arg(ap, intmax_t)));
	else if (!ft_strcmp(spec.smod, "z"))
		ft_strjoin_free(str, buf = ft_llitoa(cl.zd = va_arg(ap, size_t)));
	else if (!ft_strcmp(spec.smod, ""))
		ft_strjoin_free(str, buf = ft_itoa(cl.d = va_arg(ap, int)));
	if (buf)
		ft_strdel(&buf);
}

void	init_bbc(t_spec_elem spec, t_var4numb *v)
{
	v->buf = NULL;
	v->base = (spec.cletter == 'o' || spec.cletter == 'O') ? 8 : 10;
	if (spec.cletter == 'x' || spec.cletter == 'X')
		v->base = 16;
	v->caps = (spec.cletter == 'X') ? 1 : 0;
}

void	convert_unsigned_helper(t_var4numb *v, char **str, t_spec_elem spec, \
va_list ap)
{
	if (!(ft_strcmp(spec.smod, "l")))
		ft_strjoin_free(str, v->buf = ft_ulltoa_base(v->cl.lu = \
		va_arg(ap, unsigned long), v->base, v->caps));
	else if (!(ft_strcmp(spec.smod, "ll")))
		ft_strjoin_free(str, v->buf = ft_ulltoa_base(v->cl.llu = \
		va_arg(ap, unsigned long long), v->base, v->caps));
	else if (!(ft_strcmp(spec.smod, "h")))
		ft_strjoin_free(str, v->buf = ft_ulltoa_base(v->cl.hu = \
		va_arg(ap, unsigned int), v->base, v->caps));
	else if (!(ft_strcmp(spec.smod, "hh")))
		ft_strjoin_free(str, v->buf = ft_ulltoa_base(v->cl.hhu = \
		va_arg(ap, unsigned int), v->base, v->caps));
	else if (!(ft_strcmp(spec.smod, "j")))
		ft_strjoin_free(str, v->buf = ft_ulltoa_base(v->cl.ju = \
		va_arg(ap, uintmax_t), v->base, v->caps));
	else if (!(ft_strcmp(spec.smod, "z")))
		ft_strjoin_free(str, v->buf = ft_ulltoa_base(v->cl.zd = \
		va_arg(ap, size_t), v->base, v->caps));
	else if (!(ft_strcmp(spec.smod, "")))
		ft_strjoin_free(str, v->buf = ft_ulltoa_base(v->cl.u = \
		va_arg(ap, unsigned int), v->base, v->caps));
}

void	convert_unsigned(char **str, t_spec_elem spec, va_list ap)
{
	t_var4numb	v;

	init_bbc(spec, &v);
	convert_unsigned_helper(&v, str, spec, ap);
	if (v.buf)
		ft_strdel(&v.buf);
}

void	convert_OU(char **str, t_spec_elem spec, va_list ap)
{
	t_var4numb	v;

	init_bbc(spec, &v);
	v.cl.lu = va_arg(ap, unsigned long);
	if (spec.cletter == 'O' || spec.cletter == 'U')
		ft_strjoin_free(str, v.buf = ft_ulltoa_base(v.cl.lu, v.base, v.caps));
	if (v.buf)
		ft_strdel(&v.buf);
}