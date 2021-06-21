/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_unsigneddecimal.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: statooin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 05:56:31 by statooin          #+#    #+#             */
/*   Updated: 2020/07/29 05:56:34 by statooin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format_unsigneddecimal(t_format *pf_formats)
{
	unsigned long long	n;

	if ((pf_formats->lengt & FLG_HH) != 0)
	{
		n = (unsigned char)va_arg(pf_formats->argus, unsigned int);
		ft_format_uint(pf_formats, n);
	}
	else if ((pf_formats->lengt & FLG_H) != 0)
	{
		n = (unsigned short)va_arg(pf_formats->argus, unsigned int);
		ft_format_uint(pf_formats, n);
	}
	else if ((pf_formats->lengt & FLG_LL) != 0 ||
			(pf_formats->lengt & FLG_L) != 0)
	{
		n = va_arg(pf_formats->argus, unsigned long long);
		ft_format_ullong(pf_formats, n);
	}
	else
	{
		n = (unsigned long long)va_arg(pf_formats->argus, unsigned int);
		ft_format_uint(pf_formats, n);
	}
	return (1);
}
