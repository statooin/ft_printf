/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: statooin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 06:41:45 by statooin          #+#    #+#             */
/*   Updated: 2020/07/29 06:53:49 by statooin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long long	ft_format_hex(t_format *pf_formats)
{
	long long	n;

	if ((pf_formats->lengt & FLG_HH) != 0)
	{
		n = (unsigned char)va_arg(pf_formats->argus, int);
	}
	else if ((pf_formats->lengt & FLG_H) != 0)
	{
		n = (unsigned short)va_arg(pf_formats->argus, int);
	}
	else if ((pf_formats->lengt & FLG_LL) != 0 ||
			(pf_formats->lengt & FLG_L) != 0)
	{
		n = va_arg(pf_formats->argus, unsigned long long);
	}
	else
	{
		n = (unsigned long long)va_arg(pf_formats->argus, unsigned);
	}
	return (n);
}
