/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_lengt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: statooin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 12:43:05 by statooin          #+#    #+#             */
/*   Updated: 2020/07/27 12:52:17 by statooin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_lengt(const char *format, size_t *i, t_format *pf_formats)
{
	while (format[*i] != '\0')
	{
		if (format[*i] == 'l' && format[*i + 1] != 'l')
			pf_formats->lengt |= FLG_L;
		else if (format[*i] == 'l' && format[*i + 1] == 'l')
		{
			pf_formats->lengt |= FLG_LL;
			*i = *i + 2;
			return (1);
		}
		else if (format[*i] == 'h' && format[*i + 1] != 'h')
			pf_formats->lengt |= FLG_H;
		else if (format[*i] == 'h' && format[*i + 1] == 'h')
		{
			pf_formats->lengt |= FLG_HH;
			*i = *i + 2;
			return (1);
		}
		else
			return (1);
		*i = *i + 1;
	}
	return (1);
}
