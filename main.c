/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <vfil@student.unit.ua>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 17:43:08 by vfil              #+#    #+#             */
/*   Updated: 2018/01/12 17:43:10 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <locale.h>

int		main(void)
{
	int		ret;
	int		ret2;
	int		var;
	char	*str;

	char* l = setlocale(LC_ALL, "");
	var = 184;
	//ret = 0;
	//ret2 = 0;
	str = "longish";
    ret = ft_printf("%d\n", var);
    ret2 = printf("%d\n", var);
	printf("ret1: %d\nret2: %d\n", ret, ret2);

    return (0);
}
