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
	{
		get_symbol(res, va_arg(ap, unsigned int));
	}
}

void	convert_unistr(t_pfbuf **res, t_spec_elem spec, va_list ap)
{
	unsigned int	*unistr;
	int				i;

	if (spec.cletter)
	{
		unistr = va_arg(ap, unsigned int *);
		i = 0;
		if (!unistr)
			fill_buf_str(res, "(null)", spec);
		else
			while (unistr[i])
			{
				get_symbol(res, unistr[i]);
				i++;
			}
	}
}
