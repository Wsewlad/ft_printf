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

	char* l = setlocale(LC_ALL, "");

	// Unicode

	/*
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
	*/

	 // bonus '*'

	 /*
	ret = ft_printf("%s\n", "Hello!!");
	ret2 = printf("%s\n", "Hello!!");
	printf("ret1: %d\nret2: %d\n", ret, ret2);

	ret = ft_printf("%.*s\n", 3, "hello!!");
	ret2 = printf("%.*s\n", 3, "hello!!");
	printf("ret1: %d\nret2: %d\n", ret, ret2);
	*/

	 // undefined

	 /*
	ret = ft_printf("%zhd\n", 4294967296);
	ret2 = printf("%zhd\n", 4294967296);
	printf("ret1: %d\nret2: %d\n", ret, ret2);

	ret = ft_printf("%jhd\n", 9223372036854775807);
	ret2 = printf("%jhd\n", 9223372036854775807);
	printf("ret1: %d\nret2: %d\n", ret, ret2);

	ret = ft_printf("% -5+d\n", 256);
	ret2 = printf("% -5+d\n", 256);
	printf("ret1: %d\nret2: %d\n", ret, ret2);
	*/

	// pointer

	/*
	ret = ft_printf("%.0p, %.p\n", 0, 0);
	ret2 = printf("%.0p, %.p\n", 0, 0);
	printf("ret1: %d\nret2: %d\n", ret, ret2);

	ret = ft_printf("%.5pv", 0);
	ret2 = printf("%.5p\n", 0);
	printf("ret1: %d\nret2: %d\n", ret, ret2);

	ret = ft_printf("%9.2p\n", 1234);
	ret2 = printf("%9.2p\n", 1234);
	printf("ret1: %d\nret2: %d\n", ret, ret2);

	ret = ft_printf("%9.2p\n", 1234567);
	ret2 = printf("%9.2p\n", 1234567);
	printf("ret1: %d\nret2: %d\n", ret, ret2);

	ret = ft_printf("%2.9p\n", 1234);
	ret2 = printf("%2.9p\n", 1234);
	printf("ret1: %d\nret2: %d\n", ret, ret2);

	ret = ft_printf("%2.9p\n", 1234567);
	ret2 = printf("%2.9p\n", 1234567);
	printf("ret1: %d\nret2: %d\n", ret, ret2);
	 */

	// percent

	/*
	ret = ft_printf("%.3%\n");
	ret2 = printf("%.3%\n");
	printf("ret1: %d\nret2: %d\n", ret, ret2);

	ret = ft_printf("s: %s, p: %p, d:%d\n", "a string", &malloc, 42);
	ret2 = printf("s: %s, p: %p, d:%d\n", "a string", &malloc, 42);
	printf("ret1: %d\nret2: %d\n", ret, ret2);

	ret = ft_printf("%s%p%d%d%p%s%p%p%s\n",
					"a", &free, 1, 2, &malloc, "b", &free, &malloc, "c");
	ret2 = printf("%s%p%d%d%p%s%p%p%s\n",
				  "a", &free, 1, 2, &malloc, "b", &free, &malloc, "c");
	printf("ret1: %d\nret2: %d\n", ret, ret2);

	ret = ft_printf("aa%%bb\n");
	ret2 = printf("aa%%bb\n");
	printf("ret1: %d\nret2: %d\n", ret, ret2);

	ret = ft_printf(".%%.%%.%%.%%.%%.%%.%%.%%.\n");
	ret2 = printf(".%%.%%.%%.%%.%%.%%.%%.%%.\n");
	printf("ret1: %d\nret2: %d\n", ret, ret2);

	ret = ft_printf("%");
	ret2 = printf("%");
	printf("ret1: %d\nret2: %d\n", ret, ret2);

	ret = ft_printf("% Zoooo\n");
	ret2 = printf("% Zoooo\n");
	printf("ret1: %d\nret2: %d\n", ret, ret2);

	ret = ft_printf("{% %}\n");
	ret2 = printf("{% %}\n");
	printf("ret1: %d\nret2: %d\n", ret, ret2);
	*/

	// test X

	/*
	ret = ft_printf("before %X after\n", 42);
	ret2 = printf("before %X after\n", 42);
	printf("ret1: %d\nret2: %d\n", ret, ret2);

	ret = ft_printf("%X%X%X%X%X\n", 1, 100, 999, 42, 999988888);
	ret2 = printf("%X%X%X%X%X\n", 1, 100, 999, 42, 999988888);
	printf("ret1: %d\nret2: %d\n", ret, ret2);

	ret = ft_printf("a%Xb%Xc%Xd\n", 0, 55555, 100000);
	ret2 = printf("a%Xb%Xc%Xd\n", 0, 55555, 100000);
	printf("ret1: %d\nret2: %d\n", ret, ret2);
	*/

	ret = ft_printf("{bld}{blu}%s{eoc}{bld}{yel}%s{eoc}\n", "Hello, ", "World!!!");
	ret2 = printf("{red}%s\n", "Hello!");
	printf("ret1: %d\nret2: %d\n", ret, ret2);

	return (0);
}
