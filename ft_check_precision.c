/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_precision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: statooin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 12:43:05 by statooin          #+#    #+#             */
/*   Updated: 2020/07/29 07:28:51 by statooin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_preci(const char *format, size_t *i, t_format *pf_formats)
{
	int w;

	if (format[*i] == '.')
	{
		pf_formats->pryes = 1;
		*i = *i + 1;
		if (format[*i] == '0')
			*i = *i + 1;
		if (format[*i] > '0' && format[*i] <= '9')
		{
			pf_formats->preci = ft_atoi(&format[*i]);
			*i = *i + ft_nbrlen(pf_formats->preci, 10);
		}
		else if (format[*i] == '0')
			*i = *i + 1;
		else if (format[*i] == '*')
		{
			w = va_arg(pf_formats->argus, int);
			if (w < 0)
				pf_formats->pryes = 0;
			pf_formats->preci = w;
			*i = *i + 1;
		}
	}
	return (1);
}
