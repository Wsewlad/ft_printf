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
	unsigned int		var;

	char* l = setlocale(LC_ALL, "");
	var = 0;
	//ret = 0;
	//ret2 = -42;
    ret = ft_printf("@moulitest: %#.o %#.0o\n", 0, 0);
    ret2 = printf("@moulitest: %#.o %#.0o\n", 0, 0);
    printf("ret1: %d\nret2: %d\n", ret, ret2);
    return (0);
}
