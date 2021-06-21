/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_signes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: statooin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 10:29:20 by statooin          #+#    #+#             */
/*   Updated: 2020/07/29 03:27:55 by statooin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_signes(t_format *pf_formats, char **str, int sign)
{
	if (*str == NULL)
		return (-1);
	if (sign == -1)
		ft_strjoin_f("-", *str, str);
	if ((pf_formats->flags & FLG_PLUS) != 0 && sign == 1
		&& ((pf_formats->flags & FLG_ZERO) == 0))
	{
		ft_strjoin_f("+", *str, str);
	}
	if ((pf_formats->flags & FLG_PLUS) != 0 && sign == 1
		&& ((pf_formats->flags & FLG_ZERO) != 0))
	{
		ft_putchar_fd('+', 1);
		pf_formats->prlen++;
		if (pf_formats->width > 0)
			pf_formats->width--;
	}
	if ((pf_formats->flags & FLG_SPAC) != 0 && sign == 1)
	{
		ft_putchar_fd(' ', 1);
		pf_formats->prlen++;
		if (pf_formats->width > 0)
			pf_formats->width--;
	}
	return (1);
}
