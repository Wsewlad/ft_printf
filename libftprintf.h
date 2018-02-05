/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <vfil@student.unit.ua>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 13:48:13 by vfil              #+#    #+#             */
/*   Updated: 2018/01/18 13:48:15 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "Libft/libft.h"
# include <stdarg.h>
# include <stdio.h>

# define BUF_SIZE_PF 64

typedef struct		s_flags
{
	int				minus;
	int				plus;
	int				zero;
	int				hash;
	int				space;
}					t_flags;

typedef struct		s_spec_elem
{
	t_flags			flags;
	int				fwidth;
	int				precision;
	char			smod[3];
	char 			cletter;
}					t_spec_elem;

typedef struct 		s_pfbuf
{
	int				size;
	char 			*buf;
	struct s_pfbuf	*next;
}					t_pfbuf;

typedef void		(*t_convert)(t_pfbuf **res, t_spec_elem spec, va_list ap);

typedef struct 		s_conv
{
	char 			letter;
	t_convert		make;
}					t_conv;

typedef struct      s_var
{

}                   t_var;

int					ft_printf(const char *restrict format, ...);
int					prntf_parse(t_pfbuf **res, char *format, va_list ap);
int					check_init_specification(char *format, t_spec_elem *spec);
void				init_spec2zero(t_spec_elem *spec);
void				check_init_flags(char *format, int *step, t_spec_elem *spec);
void				check_init_fwidth(char *format, int *step, t_spec_elem *spec);
void				check_init_precision(char *format, int *step, t_spec_elem *spec);
void				check_init_modifiers(char *format, int *step, t_spec_elem *spec);
void				check_init_specifier(char *format, int *step, t_spec_elem *spec);

int					is_specifier(char c);
int					is_flag(char c);
int					is_modifier(char c);

t_conv				*init_conversion(void);
void				test(t_pfbuf **res, t_spec_elem spec, va_list ap);
void				convert_chr(t_pfbuf **res, t_spec_elem spec, va_list ap);
void				convert_str(t_pfbuf **res, t_spec_elem spec, va_list ap);
void				convert_dibd(t_pfbuf **res, t_spec_elem spec, va_list ap);
void				convert_unsigned(t_pfbuf **res, t_spec_elem spec, va_list ap);
void				convert_bou(t_pfbuf **res, t_spec_elem spec, va_list ap);
void				convert_ptr(t_pfbuf **res, t_spec_elem spec, va_list ap);
//void				convert_prcnt(t_pfbuf **res, t_spec_elem spec, va_list ap);
void				convert_unichr(t_pfbuf **res, t_spec_elem spec, va_list ap);
void				convert_unistr(t_pfbuf **res, t_spec_elem spec, va_list ap);
void				get_symbol(t_pfbuf **res, unsigned int numb);

t_pfbuf				*pf_bufnew(size_t size);
void				ft_bufadd(t_pfbuf **head, t_pfbuf *new);
void				fill_buf_str(t_pfbuf **head, char *str, t_spec_elem spec);
void				fill_buf_chr(t_pfbuf **head, char chr);
int					print_buf(t_pfbuf **head);
void				push_str(t_pfbuf **head, int len, char *str);
void				push_padding(t_pfbuf **head, int len, t_spec_elem spec, int zero);
//void                push_padd_chr(char c, t_pfbuf **res, t_spec_elem spec);
void				culc_prec_padd(int *prec, int *padd, int len, t_spec_elem spec);
void				push_prec_flags(t_pfbuf **res, t_spec_elem spec, int *min, int prec);
void		        push_unumb(t_pfbuf **res, int base, unsigned long long un, int caps);
void				ulltoa_base_buf(t_pfbuf **res, unsigned long long un, int *base_caps, t_spec_elem spec);
void				lltoa_buf(t_pfbuf **res, long long n, t_spec_elem spec);

//////	for testing	//////
void 				p(t_spec_elem *spec);

#endif
