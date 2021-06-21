/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: statooin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 05:19:21 by statooin          #+#    #+#             */
/*   Updated: 2020/07/27 05:19:30 by statooin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ft_printf -> ft_read_format ->
** ----
** (ft_check_flags, ft_check_width, ft_check_preci, ft_check_lenght,
** ft_check_speci) ->
** ----
** (ft_format_char, ft_format_string, 'p', ft_format_int, ft_format_uint,
** ft_format_lowhex, ft_format_uphex, ft_format_n, '%%') ->
** ----
** ft_format_char -> ft_print_width
** ft_format_string -> ft_print_string -> ft_print_str_n_width -> ft_print_width
** ft_format_int -> ft_apply_precision ->ft_print_signes ->ft_print_str_n_width
** ft_format_uint -> ft_apply_precision -> ft_print_str_n_width
** ft_format_lowhex -> ft_apply_precision -> ft_print_str_n_width
*/

int	ft_printf(const char *format, ...)
{
	size_t		i;
	t_format	pf_formats;

	va_start(pf_formats.argus, format);
	i = 0;
	pf_formats.prlen = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (ft_read_format(format, &i, &pf_formats) == -1)
				return (-1);
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			i++;
			pf_formats.prlen++;
		}
	}
	va_end(pf_formats.argus);
	return (pf_formats.prlen);
}
