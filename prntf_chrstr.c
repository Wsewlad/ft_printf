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
		ft_strjoin_free(str, cl.s);
}
