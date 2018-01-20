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

	if (spec.cletter == 'D' && (cl.ld = va_arg(ap, long)))
		ft_strjoin_free(str, buf = ft_itoa_ll(cl.ld));
	else if (!(ft_strcmp(spec.smod, "l")) && (cl.ld = va_arg(ap, long)))
		ft_strjoin_free(str, buf = ft_itoa_ll(cl.ld));
	else if (!(ft_strcmp(spec.smod, "ll")) && (cl.lld = va_arg(ap, \
	long long)))
		ft_strjoin_free(str, buf = ft_itoa_ll(cl.lld));
	else if (!(ft_strcmp(spec.smod, "h")) && (cl.hd = va_arg(ap, int)))
		ft_strjoin_free(str, buf = ft_itoa(cl.hd));
	else if (!(ft_strcmp(spec.smod, "hh")) && (cl.hhd = va_arg(ap, int)))
		ft_strjoin_free(str, buf = ft_itoa(cl.hhd));
	else if (!(ft_strcmp(spec.smod, "j")) && (cl.jd = va_arg(ap, intmax_t)))
		ft_strjoin_free(str, buf = ft_itoa_ll(cl.jd));
	else if (!(ft_strcmp(spec.smod, "z")) && (cl.zd = va_arg(ap, size_t)))
		ft_strjoin_free(str, buf = ft_itoa_ll(cl.zd));
	else if (!(ft_strcmp(spec.smod, "")) && (cl.d = va_arg(ap, int)))
		ft_strjoin_free(str, buf = ft_itoa(cl.d));
	ft_strdel(&buf);
}

void	convert_unsigned(char **str, t_spec_elem spec, va_list ap)
{
	char			*buf;
	int 			base;
	int 			caps;
	t_conversions	cl;

	base = (spec.cletter == 'o') ? 8 : 10;
	caps = (spec.cletter == 'X') ? 1 : 0;
	if (spec.cletter == 'x' || spec.cletter == 'X')
		base = 16;
	if (!(ft_strcmp(spec.smod, "l")) && (cl.lu = va_arg(ap, unsigned long)))
		ft_strjoin_free(str, buf = ft_itoa_base_ull(cl.lu, base, caps));
	else if (!(ft_strcmp(spec.smod, "ll")) && (cl.llu = va_arg(ap, \
	unsigned long long)))
		ft_strjoin_free(str, buf = ft_itoa_base_ull(cl.llu, base, caps));
	else if (!(ft_strcmp(spec.smod, "h")) && (cl.hu = va_arg(ap, unsigned int)))
		ft_strjoin_free(str, buf = ft_itoa_base_ull(cl.hu, base, caps));
	else if (!(ft_strcmp(spec.smod, "hh")) && (cl.hhu = va_arg(ap, unsigned int)))
		ft_strjoin_free(str, buf = ft_itoa_base_ull(cl.hhu, base, caps));
	else if (!(ft_strcmp(spec.smod, "j")) && (cl.ju = va_arg(ap, uintmax_t)))
		ft_strjoin_free(str, buf = ft_itoa_base_ull(cl.ju, base, caps));
	else if (!(ft_strcmp(spec.smod, "z")) && (cl.zd = va_arg(ap, size_t)))
		ft_strjoin_free(str, buf = ft_itoa_base_ull(cl.zd, base, caps));
	else if (!(ft_strcmp(spec.smod, "")) && (cl.u = va_arg(ap, unsigned int)))
		ft_strjoin_free(str, buf = ft_itoa_base_ull(cl.u, base, caps));
	ft_strdel(&buf);
}

void	convert_OU(char **str, t_spec_elem spec, va_list ap)
{
	char			*buf;
	int 			base;
	int 			caps;
	t_conversions	cl;

	base = (spec.cletter == 'O') ? 8 : 10;
	caps = 0;

	if (spec.cletter == 'O' && (cl.lu = va_arg(ap, unsigned long)))
		ft_strjoin_free(str, buf = ft_itoa_base_ull(cl.lu, base, caps));
	else if (spec.cletter == 'U' && (cl.lu = va_arg(ap, unsigned long)))
		ft_strjoin_free(str, buf = ft_itoa_base_ull(cl.lu, base, caps));
	ft_strdel(&buf);
}