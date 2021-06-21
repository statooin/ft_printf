/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: statooin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 12:33:56 by statooin          #+#    #+#             */
/*   Updated: 2020/07/27 12:34:33 by statooin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_flags(const char *format, size_t *i, t_format *pf_formats)
{
	while (format[*i] != '\0')
	{
		if (format[*i] == '-')
			pf_formats->flags |= FLG_MINU;
		else if (format[*i] == '+')
			pf_formats->flags |= FLG_PLUS;
		else if (format[*i] == ' ')
			pf_formats->flags |= FLG_SPAC;
		else if (format[*i] == '#')
			pf_formats->flags |= FLG_HASH;
		else if (format[*i] == '0')
			pf_formats->flags |= FLG_ZERO;
		else
			return (1);
		if ((pf_formats->flags & FLG_SPAC) != 0 && \
				(pf_formats->flags & FLG_PLUS) != 0)
			pf_formats->flags -= FLG_SPAC;
		if ((pf_formats->flags & FLG_ZERO) != 0 && \
				((pf_formats->flags & FLG_MINU)))
			pf_formats->flags -= FLG_ZERO;
		*i = *i + 1;
	}
	return (1);
}
