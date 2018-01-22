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

	if ((cl.c = (char)va_arg(ap, int)) && spec.cletter)
		ft_chrjoin_free(str, cl.c);
}

void	convert_str(char **str, t_spec_elem spec, va_list ap)
{
	t_conversions	cl;

	if ((cl.s = va_arg(ap, char *)) && spec.cletter)
		printf("%s\n", cl.s);
		ft_strjoin_free(str, cl.s);
}

void	convert_ptr(char **str, t_spec_elem spec, va_list ap)
{
	t_conversions	cl;
	char 			*buf;

	if ((cl.ld = va_arg(ap, long int)) && spec.cletter)
	{
		ft_strjoin_free(str, "0x");
		ft_strjoin_free(str, buf = ft_itoa_base(cl.ld, 16));
		ft_strdel(&buf);
	}
}