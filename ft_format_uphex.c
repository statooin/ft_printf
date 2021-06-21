/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_uphex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: statooin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 05:52:41 by statooin          #+#    #+#             */
/*   Updated: 2020/07/29 05:55:10 by statooin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format_uphex(t_format *pf_formats)
{
	char	*str;

	if ((pf_formats->flags & FLG_ZERO) != 0 && pf_formats->pryes == 1)
		pf_formats->flags ^= FLG_ZERO;
	str = ft_ulltoa_base_upp(ft_format_hex(pf_formats), 16);
	if (str == NULL)
		str = ft_strdup("(null)");
	if (str == NULL)
		return (-1);
	if (str[0] == '0' && (pf_formats->flags & FLG_HASH) != 0)
		pf_formats->flags ^= FLG_HASH;
	ft_apply_precision(pf_formats, &str);
	ft_print_hash(pf_formats, &str, "0X");
	ft_print_str_n_width(pf_formats, str);
	if (str != NULL)
		free(str);
	return (0);
}
