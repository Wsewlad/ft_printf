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

int		prntf_parse(t_pfbuf **res, char *format, va_list ap/*, t_conv *conv*/)
{
	t_spec_elem		spec;
	int				step;
	int				i;
	t_conv			conv[] = {{'s', &convert_str}, {'S', &convert_unistr}, \
	{'p', &convert_ptr}, {'d', &convert_dibd}, {'D', &convert_dibd}, \
	{'i', &convert_dibd}, {'o', &convert_unsigned}, {'O', &convert_bou}, \
	{'u', &convert_unsigned}, {'U', &convert_bou}, {'x', &convert_unsigned}, \
	{'X', &convert_unsigned}, {'c', &convert_chr}, {'C', &convert_unichr}, \
	{'%', &convert_chr}, {'0', NULL}};

	step = check_init_specification(format, &spec);
	i = 0;
	while (conv[i].letter != spec.cletter && conv[i].letter != '0')
		i++;
	if (conv[i].letter == spec.cletter)
		conv[i].make(res, spec, ap);
	else if (spec.cletter != '\0')
		convert_chr(res, spec, ap);
	return (step);
}

void	prntf_runner(t_pfbuf **res, char *format, va_list ap)
{
	int		step;
//	t_conv	*conv;

//	conv = init_conversion();
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			step = prntf_parse(res, format, ap/*, conv*/);
			format += step;
			if (!step)
				return ;
		}
		else if (*format)
		{
			fill_buf_chr(res, *format);
			format++;
		}
	}
//	ft_memdel((void**)&conv);
}

int		ft_printf(const char *restrict format, ...)
{
	va_list ap;
	t_pfbuf	*res;
	int		len;

	res = pf_bufnew(BUF_SIZE_PF);
	va_start(ap, format);
	prntf_runner(&res, (char*)format, ap);
	va_end(ap);
	len = print_buf(&res);
	return (len);
}
