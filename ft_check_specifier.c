/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_specifier.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: statooin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 06:45:45 by statooin          #+#    #+#             */
/*   Updated: 2020/07/29 06:45:58 by statooin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_speci(const char *format, size_t *i, t_format *pf_formats)
{
	if (format[*i] == 'c')
		ft_format_char(pf_formats);
	else if (format[*i] == 's')
		ft_format_string(pf_formats, 1);
	else if (format[*i] == 'p')
		ft_format_lowhex(pf_formats, 1);
	else if (format[*i] == 'd' || format[*i] == 'i')
		ft_formatdecimal(pf_formats);
	else if (format[*i] == 'u')
		ft_format_unsigneddecimal(pf_formats);
	else if (format[*i] == 'x')
		ft_format_lowhex(pf_formats, 0);
	else if (format[*i] == 'X')
		ft_format_uphex(pf_formats);
	else if (format[*i] == 'n')
		ft_format_n(pf_formats);
	else if (format[*i] == '%')
		ft_format_string(pf_formats, 0);
	else if (format[*i] == 'o')
		ft_format_octal(pf_formats, 0);
	else
		return (-1);
	*i = *i + 1;
	return (1);
}
