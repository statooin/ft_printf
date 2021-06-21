/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: statooin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 12:39:32 by statooin          #+#    #+#             */
/*   Updated: 2020/07/27 12:40:23 by statooin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_width(const char *format, size_t *i, t_format *pf_formats)
{
	int w;

	pf_formats->width = 0;
	if (format[*i] == '*')
	{
		w = va_arg(pf_formats->argus, int);
		if (w < 0)
		{
			w = -w;
			pf_formats->flags |= FLG_MINU;
		}
		pf_formats->width = w;
		*i = *i + 1;
	}
	else if (format[*i] > '0' && format[*i] <= '9')
	{
		pf_formats->width = ft_atoi(&format[*i]);
		*i = *i + ft_nbrlen(pf_formats->width, 10);
	}
	return (1);
}
