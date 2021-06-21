/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str_n_width.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: statooin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 13:47:12 by statooin          #+#    #+#             */
/*   Updated: 2020/07/27 13:47:15 by statooin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str_n_width(t_format *pf_formats, char *str)
{
	size_t str_len;

	str_len = ft_strlen(str);
	if (pf_formats->width > str_len)
	{
		if ((pf_formats->flags & FLG_MINU) != 0)
		{
			ft_putstr_fd(str, 1);
			ft_print_width(pf_formats, str_len);
		}
		else
		{
			ft_print_width(pf_formats, str_len);
			ft_putstr_fd(str, 1);
		}
	}
	else
	{
		ft_putstr_fd(str, 1);
	}
	pf_formats->prlen = pf_formats->prlen + str_len;
	return (1);
}
