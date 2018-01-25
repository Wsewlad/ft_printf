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

# define BUF_SIZE_PF 100

typedef union			u_conversions
{
	char				c;
	int					d;
	long				ld;
	long long			lld;
	short				hd;
	signed char			hhd;
	intmax_t			jd;
	size_t				zd;
	unsigned int		u;
	unsigned short		hu;
	unsigned char		hhu;
	unsigned long		lu;
	unsigned long long llu;
	uintmax_t			ju;
	char				*s;
	void				*p;
}						t_conversions;

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

typedef void		(*t_convert)(char **str, t_spec_elem spec, va_list ap);

typedef struct 		s_conv
{
	char 			letter;
	t_convert		make;
}					t_conv;

typedef struct		s_var4numb
{
	char 			*buf;
	int 			base;
	int 			caps;
	t_conversions	cl;
}					t_var4numb;

int					ft_printf(const char *restrict format, ...);
int					prntf_parse(char **res, char *format, va_list ap);
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
void				test(char **str, t_spec_elem spec, va_list ap);
void				convert_chr(char **str, t_spec_elem spec, va_list ap);
void				convert_str(char **str, t_spec_elem spec, va_list ap);
void				convert_diD(char **str, t_spec_elem spec, va_list ap);
void				convert_unsigned(char **str, t_spec_elem spec, va_list ap);
void				convert_OU(char **str, t_spec_elem spec, va_list ap);
void				convert_ptr(char **str, t_spec_elem spec, va_list ap);
void				convert_prcnt(char **str, t_spec_elem spec, va_list ap);
void				convert_unichr(char **str, t_spec_elem spec, va_list ap);

//////	for testing	//////
void 				p(t_spec_elem *spec);

#endif
