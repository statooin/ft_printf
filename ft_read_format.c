/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: statooin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 12:31:49 by statooin          #+#    #+#             */
/*   Updated: 2020/07/27 12:31:59 by statooin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** read: % [flags] [width] [.precision] [length] specifier
*/

int	ft_read_format(const char *format, size_t *i, t_format *pf_formats)
{
	pf_formats->flags = FLG_NONE;
	pf_formats->width = 0;
	pf_formats->pryes = 0;
	pf_formats->preci = 0;
	pf_formats->lengt = FLG_NONE;
	if (format[*i] == '\0')
	{
		return (-1);
	}
	else
	{
		ft_check_flags(format, i, pf_formats);
		ft_check_width(format, i, pf_formats);
		ft_check_preci(format, i, pf_formats);
		ft_check_lengt(format, i, pf_formats);
		ft_check_speci(format, i, pf_formats);
	}
	return (1);
}
