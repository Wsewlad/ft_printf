/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <vfil@student.unit.ua>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 17:42:46 by vfil              #+#    #+#             */
/*   Updated: 2018/01/12 17:42:50 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		prntf_parse(char **res, char *format, va_list ap)
{
	t_spec_elem		spec;
	int				step;
	int				i;
	t_conv			*conversion;

	step = check_init_specification(format, &spec);
	conversion = init_conversion();
	i = 0;
	while (i < 14)
	{
		if (conversion[i].letter == spec.cletter)
			conversion[i].make(res, spec.smod, ap);
		i++;
	}
	ft_memdel((void**)&conversion);
	return (step);
}

void	ft_printf(const char *restrict format, ...)
{
	va_list ap;
	char	*res;
	int		step;

	step = 0;
	res = ft_strnew(0);
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			step = prntf_parse(&res, (char*)format, ap);
			format += step;
		}
		if (*format)
		{
			ft_chrjoin_free(&res, *format);
			format++;
		}
	}
	va_end(ap);
	ft_putstr(res);
	ft_strdel(&res);
}
