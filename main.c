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
	int 	var2;

	char* l = setlocale(LC_ALL, "");
	var = 42;
	var2 = -42;
	//ret = 0;
	//ret2 = -42;

	ret = ft_printf("%012u\n", var);
	ret2 = printf("%012u\n", var);
	printf("ret1: %d\nret2: %d\n", ret, ret2);

	ret = ft_printf("%#12u\n", var);
	ret2 = printf("%#12u\n", var);
	printf("ret1: %d\nret2: %d\n", ret, ret2);

	ret = ft_printf("%#012u\n", var);
	ret2 = printf("%#012u\n", var);
	printf("ret1: %d\nret2: %d\n", ret, ret2);

	ret = ft_printf("%-12u\n", var);
	ret2 = printf("%-12u\n", var);
	printf("ret1: %d\nret2: %d\n", ret, ret2);

	ret = ft_printf("%-#12u\n", var);
	ret2 = printf("%-#12u\n", var);
	printf("ret1: %d\nret2: %d\n", ret, ret2);

	ret = ft_printf("%12.4u\n", var);
	ret2 = printf("%12.4u\n", var);
	printf("ret1: %d\nret2: %d\n", ret, ret2);

	ret = ft_printf("%-12.4d\n", var);
	ret2 = printf("%-12.4u\n", var);
	printf("ret1: %d\nret2: %d\n", ret, ret2);

	ret = ft_printf("%#x\n", var);
	ret2 = printf("%#x\n", var);
	printf("ret1: %d\nret2: %d\n", ret, ret2);

	ret = ft_printf("%#X\n", var);
	ret2 = printf("%#X\n", var);
	printf("ret1: %d\nret2: %d\n", ret, ret2);

	ret = ft_printf("%#o\n", var);
	ret2 = printf("%#o\n", var);
	printf("ret1: %d\nret2: %d\n", ret, ret2);

	ret = ft_printf("%#08o\n", var);
	ret2 = printf("%#08o\n", var);
	printf("ret1: %d\nret2: %d\n", ret, ret2);
    return (0);
}
