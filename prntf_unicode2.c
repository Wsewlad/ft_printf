/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prntf_unicode2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <vfil@student.unit.ua>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 16:55:28 by vfil              #+#    #+#             */
/*   Updated: 2018/01/26 16:55:30 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	get_two_bytes(char **str, unsigned int u)
{
	unsigned int	mask02;
	unsigned char	p1;
	unsigned char	p2;

	mask02 = 49280;
	p2 = (u << 26) >> 26;
	p1 = ((u >> 6) << 27) >> 27;
	ft_chrjoin_free(str, (char)((mask02 >> 8) | p1));
	ft_chrjoin_free(str, (char)(((mask02 << 24) >> 24) | p2));
}

static void	get_three_bytes(char **str, unsigned int u)
{
	unsigned int	mask03;
	unsigned char	p1;
	unsigned char	p2;
	unsigned char	p3;

	mask03 = 14712960;
	p3 = (u << 26) >> 26;
	p2 = ((u >> 6) << 26) >> 26;
	p1 = ((u >> 12) << 28) >> 28;
	ft_chrjoin_free(str, (char)((mask03 >> 16) | p1));
	ft_chrjoin_free(str, (char)(((mask03 << 16) >> 24) | p2));
	ft_chrjoin_free(str, (char)(((mask03 << 24) >> 24) | p3));
}

static void	get_four_bytes(char **str, unsigned int u)
{
	unsigned int	mask04;
	unsigned char	p1;
	unsigned char	p2;
	unsigned char	p3;
	unsigned char	p4;

	mask04 = 4034953344;
	p4 = (u << 26) >> 26;
	p3 = ((u >> 6) << 26) >> 26;
	p2 = ((u >> 12) << 26) >> 26;
	p1 = ((u >> 18) << 28) >> 28;
	ft_chrjoin_free(str, (char)((mask04 >> 24) | p1));
	ft_chrjoin_free(str, (char)(((mask04 << 8) >> 24) | p2));
	ft_chrjoin_free(str, (char)(((mask04 << 16) >> 24) | p3));
	ft_chrjoin_free(str, (char)(((mask04 << 24) >> 24) | p4));
}

void		get_symbol(char **str, unsigned int numb)
{
	int				bits;
	unsigned int	n;

	bits = 0;
	n = numb;
	while (n)
	{
		n /= 2;
		bits++;
	}
	if (bits <= 7)
		ft_chrjoin_free(str, (char)numb);
	else if (bits <= 11)
		get_two_bytes(str, numb);
	else if (bits <= 16)
		get_three_bytes(str, numb);
	else if (bits <= 21)
		get_four_bytes(str, numb);
}
