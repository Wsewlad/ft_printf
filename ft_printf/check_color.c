/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <vfil@student.unit.ua>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 19:09:01 by vfil              #+#    #+#             */
/*   Updated: 2018/02/16 19:09:06 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	check_color(t_list **res, char *format)
{
	t_spec_elem	spec;
	const t_clr	col[] = {{"{blk}", "\e[30m"}, {"{red}", "\e[31m"},
							{"{grn}", "\e[32m"}, {"{yel}", "\e[33m"},
							{"{blu}", "\e[34m"}, {"{mag}", "\e[35m"},
							{"{cyn}", "\e[36m"}, {"{gry}", "\e[37m"},
							{"{bld}", "\e[1m"}, {"{eoc}", "\e[0m"},
							{NULL, NULL}};
	int			i;

	init_spec2zero(&spec);
	i = 0;
	while (col[i].tmp)
	{
		if (ft_strnstr(format, col[i].tmp, 5))
		{
			fill_buf_str(res, col[i].code, spec);
			return (5);
		}
		i++;
	}
	return (0);
}
