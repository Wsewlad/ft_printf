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
	intmax_t	var;

	var = 9223372036854775807;
    ft_printf("ft_printf %jd\n", var);
    //system("leaks a.out");
    printf("printf %jd\n", var);

    return (0);
}
