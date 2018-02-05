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

/*void	push_padd_chr(char c, t_pfbuf **res, t_spec_elem spec)
{
    if (!spec.flags.minus)
    {
        push_padding(res, spec.fwidth ? spec.fwidth - 1 : spec.fwidth, spec, 0);
        fill_buf_chr(res, c);
    }
    else
    {
        fill_buf_chr(res, c);
        push_padding(res, spec.fwidth ? spec.fwidth - 1 : spec.fwidth, spec, 0);
    }
}*/

void	convert_chr(t_pfbuf **res, t_spec_elem spec, va_list ap)
{
	char c;

	if (!ft_strcmp(spec.smod, "l"))
		convert_unichr(res, spec, ap);
	else
	{
		c = (spec.cletter == '%') ? '%' : va_arg(ap, int);
        if (!spec.flags.minus)
        {
            push_padding(res, spec.fwidth ? spec.fwidth - 1 : spec.fwidth, spec, 0);
            fill_buf_chr(res, c);
        }
        else
        {
            fill_buf_chr(res, c);
            push_padding(res, spec.fwidth ? spec.fwidth - 1 : spec.fwidth, spec, 0);
        }
	}
}

void	convert_str(t_pfbuf **res, t_spec_elem spec, va_list ap)
{
	char	*str;

	if (!ft_strcmp(spec.smod, "l"))
		convert_unistr(res, spec, ap);
	else
	{
		str = va_arg(ap, char *);
		if (str == NULL)
			str = "(null)";
		fill_buf_str(res, str, spec);
	}
}

void	convert_ptr(t_pfbuf **res, t_spec_elem spec, va_list ap)
{
	int base_caps[2];

	base_caps[0] = 16;
	base_caps[1] = 0;
	if (spec.cletter)
	{
		fill_buf_chr(res, '0');
		fill_buf_chr(res, 'x');
		push_unumb(res, base_caps[0], va_arg(ap, unsigned long), base_caps[1]);
	}
}

/*void	convert_prcnt(t_pfbuf **res, t_spec_elem spec, va_list ap)
{
	char	c;

	if (ap)
	{
		c = '%';
		if (!spec.flags.minus)
		{
			push_padding(res, spec.fwidth ? spec.fwidth - 1 : spec.fwidth, spec, 0);
			fill_buf_chr(res, c);
		}
		else
		{
			fill_buf_chr(res, c);
			push_padding(res, spec.fwidth ? spec.fwidth - 1 : spec.fwidth, spec, 0);
		}
	}
}*/