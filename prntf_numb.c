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

void	convert_int(char **res, char *smod, va_list ap)
{
	char	*buf;
	char 	*buf2;
	t_conversions	cl;

	buf2 = smod;
	if ((cl.d = va_arg(ap, int)))
	{
		ft_strjoin_free(res, buf = ft_itoa(cl.d));
		ft_strdel(&buf);
	}
}