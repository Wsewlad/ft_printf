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

void	test(char **res, char *smod, va_list ap)
{
	char	*buf;
	t_conversions	cl;

	buf = smod;
	if ((cl.s = va_arg(ap, char *)))
		ft_strjoin_free(res, "_test_");
}

void	convert_chr(char **res, char *smod, va_list ap)
{
	char	*buf;
	t_conversions	cl;

	buf = smod;
	if ((cl.c = (char)va_arg(ap, int)))
		ft_chrjoin_free(res, cl.c);
}

void	convert_str(char **res, char *smod, va_list ap)
{
	char	*buf;
	t_conversions	cl;

	buf = smod;
	if ((cl.s = va_arg(ap, char *)))
		ft_strjoin_free(res, cl.s);
}
