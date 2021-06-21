/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: statooin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 13:53:07 by statooin          #+#    #+#             */
/*   Updated: 2020/07/27 13:53:19 by statooin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format_char(t_format *pf_formats)
{
	char c_print;

	c_print = (char)va_arg(pf_formats->argus, int);
	if (pf_formats->width > 1)
		if ((pf_formats->flags & FLG_MINU) != 0)
		{
			ft_putchar_fd(c_print, 1);
			ft_print_width(pf_formats, 1);
		}
		else
		{
			ft_print_width(pf_formats, 1);
			ft_putchar_fd(c_print, 1);
		}
	else
		ft_putchar_fd(c_print, 1);
	pf_formats->prlen++;
	return (1);
}
