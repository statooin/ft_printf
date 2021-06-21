/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: statooin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 04:32:46 by statooin          #+#    #+#             */
/*   Updated: 2020/07/30 11:50:16 by statooin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdio.h>

# define FLG_NONE   0b00000000
# define FLG_MINU   0b00000001
# define FLG_PLUS   0b00000010
# define FLG_SPAC   0b00000100
# define FLG_HASH   0b00001000
# define FLG_ZERO   0b00010000

# define FLG_L   0b00000001
# define FLG_LL   0b00000010
# define FLG_H   0b00000100
# define FLG_HH   0b00001000

typedef struct			s_format
{
	unsigned char	flags;
	size_t			width;
	size_t			preci;
	unsigned char	lengt;
	unsigned char	speci;
	va_list			argus;
	size_t			prlen;
	int				pryes;
}						t_format;

int						ft_apply_flags(t_format *pf_formats);
int						ft_format_ullong(t_format *pf_formats,
		unsigned long long n);
int						ft_format_octal(t_format *pf_formats, int pointer);
int						ft_format_llong(t_format *pf_formats, long long n);
int						ft_print_hash(t_format *pf_formats,
		char **str, char *hash);
int						ft_print_minus(t_format *pf_formats, char **str);
int						ft_print_signes(t_format *pf_formats,
		char **str, int sign);
int						ft_apply_precision(t_format *pf_formats, char **str);
unsigned long long		ft_format_hex(t_format *pf_formats);
int						ft_format_unsigneddecimal(t_format *pf_formats);
int						ft_formatdecimal(t_format *pf_formats);
int						ft_check_lengt(const char *format,
		size_t *i, t_format *pf_formats);
int						ft_print_nbr_n_width(t_format *pf_formats, char **str);
int						ft_print_str_n_width(t_format *pf_formats, char *str);
int						ft_format_n(t_format *pf_formats);
int						ft_format_uphex(t_format *pf_formats);
int						ft_format_lowhex(t_format *pf_formats, int pointer);
int						ft_print_width(t_format *pf_formats, size_t src_len);
int						ft_format_uint(t_format *pf_formats, unsigned int n);
int						ft_format_int(t_format *pf_formats, int n);
int						ft_print_string(t_format *pf_formats, char *str);
int						ft_format_string(t_format *pf_formats, int take_arg);
int						ft_format_char(t_format *pf_formats);
int						ft_check_flags(const char *format,
		size_t *i, t_format *pf_formats);
int						ft_check_width(const char *format,
		size_t *i, t_format *pf_formats);
int						ft_check_preci(const char *format,
		size_t *i, t_format *pf_formats);
int						ft_check_speci(const char *format,
		size_t *i, t_format *pf_formats);
int						ft_read_format(const char *format,
		size_t *i, t_format *pf_formats);
int						ft_printf(const char *format, ...);
#endif
