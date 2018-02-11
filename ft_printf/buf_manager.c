/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buf_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <vfil@student.unit.ua>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 14:46:52 by vfil              #+#    #+#             */
/*   Updated: 2018/01/24 14:46:54 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_pfbuf		*pf_bufnew(size_t size)
{
	t_pfbuf	*new_buf;

	new_buf = (t_pfbuf*)malloc(sizeof(t_list));
	if (new_buf)
	{
		if ((new_buf->buf = (char*)malloc(sizeof(char) * size)))
		{
			new_buf->size = 0;
			new_buf->next = NULL;
		}
		else
			free(new_buf);
	}
	return (new_buf);
}

void		ft_bufadd(t_pfbuf **res, t_pfbuf *new)
{
	t_pfbuf *buf;

	buf = *res;
	if (*res && new)
	{
		while (buf->next)
			buf = buf->next;
		buf->next = new;
	}
}

void		fill_buf_str(t_pfbuf **res, char *str, t_spec_elem spec)
{
	int len;
	int padd;

	len = ft_strlen(str);
	if (spec.precision != -1)
		len = (spec.precision < len) ? spec.precision : len;
	padd = (spec.fwidth > len) ? spec.fwidth - len : 0;
	if (!spec.flags.minus)
	{
		if (spec.flags.zero && spec.precision == 0 && !len)
			push_padding(res, padd, spec, 1);
		else
			push_padding(res, padd, spec, 0);
		push_str(res, len, str);
	}
	else
	{
		push_str(res, len, str);
		push_padding(res, padd, spec, 0);
	}
}

void		fill_buf_chr(t_pfbuf **res, char chr)
{
	int		i;
	t_pfbuf	*new;
	t_pfbuf	*crawler;

	crawler = *res;
	i = crawler->size;
	if (crawler->size < BUF_SIZE_PF)
	{
		crawler->buf[i] = chr;
		crawler->size++;
	}
	else
	{
		new = pf_bufnew(BUF_SIZE_PF);
		ft_bufadd(&crawler, new);
		crawler = crawler->next;
		fill_buf_chr(&crawler, chr);
	}
}

int			print_buf(t_pfbuf **res)
{
	int		len;
	t_pfbuf	*crawler;

	len = 0;
	crawler = *res;
	while (crawler)
	{
		len += write(1, crawler->buf, crawler->size);
		crawler = crawler->next;
	}
	while (*res)
	{
		ft_strdel(&((*res)->buf));
		crawler = (*res)->next;
		free(*res);
		*res = crawler;
	}
	*res = NULL;
	return (len);
}
