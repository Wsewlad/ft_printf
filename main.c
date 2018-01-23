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

int		main(void)
{
	int ret;
	int ret2;
	int var;

	var = 0;
	//ret2 = 0;
    ret = ft_printf("11%c11\n", 0);
    // system("leaks a.out");
    ret2 = printf("11%c11\n", 0);
	printf("\nret1: %d\nret2: %d\n", ret, ret2);

    return (0);
}
