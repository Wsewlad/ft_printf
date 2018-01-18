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

void	convert_int(char **str, t_spec_elem spec, va_list ap)
{
	char			*buf;
	t_conversions	cl;

	if ((ft_strcmp(spec.smod, "l") == 0) && (cl.ld = va_arg(ap, long)))
		ft_strjoin_free(str, buf = ft_itoa_longlong(cl.ld));
	else if ((ft_strcmp(spec.smod, "ll") == 0) && (cl.lld = va_arg(ap, \
	long long)))
		ft_strjoin_free(str, buf = ft_itoa_longlong(cl.lld));
	else if ((ft_strcmp(spec.smod, "h") == 0) && (cl.hd = va_arg(ap, int)))
		ft_strjoin_free(str, buf = ft_itoa_longlong(cl.hd));
	else if ((ft_strcmp(spec.smod, "hh") == 0) && (cl.hhd = va_arg(ap, int)))
		ft_strjoin_free(str, buf = ft_itoa_longlong(cl.hhd));
	else if ((ft_strcmp(spec.smod, "j") == 0) && (cl.jd = va_arg(ap, intmax_t)))
		ft_strjoin_free(str, buf = ft_itoa_longlong(cl.jd));
	else if ((ft_strcmp(spec.smod, "") == 0) && (cl.d = va_arg(ap, int)))
		ft_strjoin_free(str, buf = ft_itoa_longlong(cl.d));
	ft_strdel(&buf);
}
