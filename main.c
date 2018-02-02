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
	var = -45;
	//ret = 0;
	//ret2 = -42;
	str = "longish";
    ret = ft_printf("%12d\n", var);
    ret2 = printf("%12d\n", var);
	printf("ret1: %d\nret2: %d\n", ret, ret2);
	ret = ft_printf("%012d\n", var);
	ret2 = printf("%012d\n", var);
	printf("ret1: %d\nret2: %d\n", ret, ret2);
	ret = ft_printf("% 012d\n", var);
	ret2 = printf("% 012d\n", var);
	printf("ret1: %d\nret2: %d\n", ret, ret2);
	ret = ft_printf("%+12d\n", var);
	ret2 = printf("%+12d\n", var);
	printf("ret1: %d\nret2: %d\n", ret, ret2);
	ret = ft_printf("%+012d\n", var);
	ret2 = printf("%+012d\n", var);
	printf("ret1: %d\nret2: %d\n", ret, ret2);
	ret = ft_printf("%-12d\n", var);
	ret2 = printf("%-12d\n", var);
	printf("ret1: %d\nret2: %d\n", ret, ret2);
	ret = ft_printf("%- 12d\n", var);
	ret2 = printf("%- 12d\n", var);
	printf("ret1: %d\nret2: %d\n", ret, ret2);
	ret = ft_printf("%-+12d\n", var);
	ret2 = printf("%-+12d\n", var);
	printf("ret1: %d\nret2: %d\n", ret, ret2);
	ret = ft_printf("%12.4d\n", var);
	ret2 = printf("%12.4d\n", var);
	printf("ret1: %d\nret2: %d\n", ret, ret2);
	ret = ft_printf("%-12.4d\n", var);
	ret2 = printf("%-12.4d\n", var);
	printf("ret1: %d\nret2: %d\n", ret, ret2);

    return (0);
}
