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
	int padd;
	int prec;

	len = ft_strlen(str);
	prec = 0;
	if (spec.precision != -1)
	{
		len = (spec.precision < len) ? spec.precision : len;
		prec = (spec.fwidth > len && spec.flags.zero && !spec.flags.minus) ?
			 spec.fwidth - len : 0;
	}
	padd = (spec.fwidth > len && !spec.flags.zero) ? spec.fwidth - len : 0;
	if (!spec.flags.minus)
	{
		push_padding(head, padd, spec, 0);
		push_padding(head, prec, spec, 1);
		push_str(head, len, str);
	}
	else
	{
		push_str(head, len, str);
		push_padding(head, padd, spec, 0);
	}
}

void	fill_buf_chr(t_pfbuf **head, char chr)
{
	int 	i;
	t_pfbuf *new;
	t_pfbuf *crawler;

	crawler = *head;
	i = crawler->size;
	if (crawler->size < BUF_SIZE_PF)
	{
		crawler->buf[i] = chr;
		crawler->size++;
	}
	else
	{
		new = pf_bufnew(BUF_SIZE_PF);
		ft_bzero(new, BUF_SIZE_PF);
		ft_bufadd(&crawler, new);
        crawler = crawler->next;
		fill_buf_chr(&crawler, chr);
	}
}

int		print_buf(t_pfbuf **head)
{
	int 	len;
	t_pfbuf *crawler;

	len = 0;
	crawler = *head;
	while (crawler)
	{
		len += write(1, crawler->buf, crawler->size);
		crawler = crawler->next;
	}
    while (*head)
    {
        ft_strdel(&((*head)->buf));
        crawler = (*head)->next;
        free(*head);
        *head = crawler;
    }
	*head = NULL;
	return (len);
}