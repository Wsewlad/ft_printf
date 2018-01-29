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

int		prntf_parse(t_pfbuf **res, char *format, va_list ap)
{
	t_spec_elem		spec;
	int				step;
	int				i;
	t_conv			*conversion;
	char 			*str;

	step = check_init_specification(format, &spec);
	conversion = init_conversion();
	str = ft_strnew(0);
	i = 0;
	while (i < 15)
	{
		if (conversion[i].letter == spec.cletter)
			conversion[i].make(&str, spec, ap);
		i++;
	}
	fill_buf_str(res, str);
	ft_strdel(&str);
	ft_memdel((void**)&conversion);

	return (step);
}

int		ft_printf(const char *restrict format, ...)
{
	va_list ap;
	t_pfbuf	*res;
	int		step;

	step = 0;
	res = pf_bufnew(BUF_SIZE_PF);
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			step = prntf_parse(&res, (char*)format, ap);
			format += step;
			if (!step)
			{
				//ft_strdel(&res);
				//print_buf(&res);
				return (0);
			}
		}
		else if (*format)
		{
			fill_buf_chr(&res, *format);
			format++;
		}
	}
	va_end(ap);
	step = print_buf(&res);
	//step = ft_strlen(res);
	//ft_strdel(&res);
	return (step);
}
