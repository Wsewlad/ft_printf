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
		if ((new_buf->buf = ft_memalloc(size)))
		{
			ft_bzero(new_buf->buf, size);
			new_buf->size = 0;
			new_lst->next = NULL;
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