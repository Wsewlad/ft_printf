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
			ft_bzero(new_buf->buf, size);
			new_buf->size = 0;
			new_buf->next = NULL;
		}
		else
			free(new_buf);
	}
	return (new_buf);
}

void	ft_bufadd(t_pfbuf **head, t_pfbuf *new)
{
	t_pfbuf *buf;

	buf = *head;
	if (*head && new)
	{
		while (buf->next)
			buf = buf->next;
		buf->next = new;
	}
}

void	fill_buf_str(t_pfbuf **head, char *str, t_spec_elem spec)
{
	int len;

	len = ft_strlen(str);
	if (spec.precision != -1)
		len = (spec.precision < len) ? spec.precision : len;
	if (!spec.flags.minus)
	{
		push_padding(head, (spec.fwidth > len) ? spec.fwidth - len : 0, spec, 0);
		push_str(head, len, str);
	}
	else
	{
		push_str(head, len, str);
		push_padding(head, (spec.fwidth > len) ? spec.fwidth - len : 0, spec, 0);
	}
}

void	fill_buf_chr(t_pfbuf **head, char chr)
{
	int 	i;
	t_pfbuf *new;
	t_pfbuf *crawler;

	new = NULL;
	crawler = *head;
	while (crawler->next && crawler->size == BUF_SIZE_PF)
		crawler = crawler->next;
	i = crawler->size;
	if (crawler->size < BUF_SIZE_PF)
	{
		crawler->buf[i] = chr;
		crawler->size++;
	}
	else if (crawler->size == BUF_SIZE_PF)
	{
		new = pf_bufnew(BUF_SIZE_PF);
		ft_bzero(new, BUF_SIZE_PF);
		ft_bufadd(&crawler, new);
		fill_buf_chr(&crawler, chr);
	}
}

int		print_buf(t_pfbuf **head)
{
	int 	len;
	t_pfbuf *crawler;
	t_pfbuf *tmp;

	len = 0;
	crawler = *head;
	while (crawler)
	{
		len += write(1, crawler->buf, crawler->size);
		crawler = crawler->next;
	}
	crawler = *head;
	while (crawler)
	{
		ft_strdel(&(crawler->buf));
		tmp = crawler->next;
		free(crawler);
		crawler = tmp;
	}
	*head = NULL;
	return (len);
}