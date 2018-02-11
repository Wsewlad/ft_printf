/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <vfil@student.unit.ua>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 17:43:08 by vfil              #+#    #+#             */
/*   Updated: 2018/02/11 13:39:16 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <locale.h>
#include <stdio.h>

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

	ret = ft_printf("%4.3S\n", L"我是一只猫。");
	ret2 = printf("%4.3S\n", L"我是一只猫。");
	printf("ret1: %d\nret2: %d\n", ret, ret2);

	ret = ft_printf("%.3S\n", L"我是一只猫。");
	ret2 = printf("%.3S\n", L"我是一只猫。");
	printf("ret1: %d\nret2: %d\n", ret, ret2);

	ret = ft_printf("%4S\n", L"我是一只猫。");
	ret2 = printf("%4S\n", L"我是一只猫。");
	printf("ret1: %d\nret2: %d\n", ret, ret2);

	ret = ft_printf("%15.3S\n", L"我是一只猫。");
	ret2 = printf("%15.3S\n", L"我是一只猫。");
	printf("ret1: %d\nret2: %d\n", ret, ret2);

	ret = ft_printf("{%05.S}\n", L"42 c est cool");
	ret2 = printf("{%05.S}\n", L"42 c est cool");
	printf("ret1: %d\nret2: %d\n", ret, ret2);

	ret = ft_printf("%030S\n", L"我是一只猫。");
	ret2 = printf("%030S\n", L"我是一只猫。");
	printf("ret1: %d\nret2: %d\n", ret, ret2);

	ret = ft_printf("%-30S\n", L"我是一只猫。");
	ret2 = printf("%-30S\n", L"我是一只猫。");
	printf("ret1: %d\nret2: %d\n", ret, ret2);

	ret = ft_printf("%30S\n", L"我是一只猫。");
	ret2 = printf("%30S\n", L"我是一只猫。");
	printf("ret1: %d\nret2: %d\n", ret, ret2);

	ret = ft_printf("%.3S\n", L"我是一只猫。");
	ret2 = printf("%.3S\n", L"我是一只猫。");
	printf("ret1: %d\nret2: %d\n", ret, ret2);

	ret = ft_printf("%.6S\n", L"我是一只猫。");
	ret2 = printf("%.6S\n", L"我是一只猫。");
	printf("ret1: %d\nret2: %d\n", ret, ret2);

	ret = ft_printf("%.4S\n", L"我是一只猫。");
	ret2 = printf("%.4S\n", L"我是一只猫。");
	printf("ret1: %d\nret2: %d\n", ret, ret2);

	ret = ft_printf("www %15.5S\n", L"我是一只猫。");
	ret2 = printf("www %15.5S\n", L"我是一只猫。");
	printf("ret1: %d\nret2: %d\n", ret, ret2);

	ret = ft_printf("%C\n", L"我");
	ret2 = printf("%C\n", L"我");
	printf("ret1: %d\nret2: %d\n", ret, ret2);

	ret = ft_printf("%c\n", 'c');
	ret2 = printf("%c\n", 'c');
	printf("ret1: %d\nret2: %d\n", ret, ret2);

	printf("MB_CUR_MAX size: %d\n", MB_CUR_MAX);

	return (0);
}
