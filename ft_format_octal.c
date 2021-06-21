/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_octal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: statooin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 06:01:38 by statooin          #+#    #+#             */
/*   Updated: 2020/07/29 06:08:02 by statooin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format_octal(t_format *pf_formats, int pointer)
{
	char	*str;

	if ((pf_formats->flags & FLG_ZERO) != 0 && pf_formats->pryes == 1)
		pf_formats->flags ^= FLG_ZERO;
	if (pointer == 1)
		str = ft_ulltoa_base_low(
				va_arg(pf_formats->argus, unsigned long long), 16);
	else
		str = ft_ulltoa_base_low(ft_format_hex(pf_formats), 8);
	if (str == NULL)
		str = ft_strdup("(null)");
	if (str == NULL)
		return (-1);
	if (str[0] == '0' && (pf_formats->flags & FLG_HASH) != 0 && pointer == 0)
		pf_formats->flags ^= FLG_HASH;
	ft_apply_precision(pf_formats, &str);
	ft_print_hash(pf_formats, &str, "0x");
	ft_print_str_n_width(pf_formats, str);
	if (str != NULL)
		free(str);
	return (0);
}
