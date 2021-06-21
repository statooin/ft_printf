/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: statooin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 10:29:20 by statooin          #+#    #+#             */
/*   Updated: 2020/07/28 10:29:26 by statooin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_width(t_format *pf_formats, size_t src_len)
{
	src_len = pf_formats->width - src_len;
	while (src_len > 0)
	{
		if ((pf_formats->flags & FLG_ZERO) != 0)
			ft_putchar_fd('0', 1);
		else
			ft_putchar_fd(' ', 1);
		src_len--;
		pf_formats->prlen++;
	}
	return (1);
}
