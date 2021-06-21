/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_decimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: statooin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 06:44:25 by statooin          #+#    #+#             */
/*   Updated: 2020/07/29 07:23:04 by statooin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_formatdecimal(t_format *pf_formats)
{
	long long	n;

	if ((pf_formats->lengt & FLG_HH) != 0)
	{
		n = (char)va_arg(pf_formats->argus, int);
		ft_format_int(pf_formats, n);
	}
	else if ((pf_formats->lengt & FLG_H) != 0)
	{
		n = (short)va_arg(pf_formats->argus, int);
		ft_format_int(pf_formats, n);
	}
	else if ((pf_formats->lengt & FLG_LL) != 0 ||
			(pf_formats->lengt & FLG_L) != 0)
	{
		n = va_arg(pf_formats->argus, long long);
		ft_format_llong(pf_formats, n);
	}
	else
	{
		n = (long long)va_arg(pf_formats->argus, int);
		ft_format_llong(pf_formats, n);
	}
	return (1);
}
