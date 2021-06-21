/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_ullong.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: statooin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 02:58:53 by statooin          #+#    #+#             */
/*   Updated: 2020/07/29 05:57:50 by statooin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format_ullong(t_format *pf_formats, unsigned long long n)
{
	char *str;

	str = ft_ulltoa_base_low(n, 10);
	if (str == NULL)
		str = ft_strdup("(null)");
	if (str == NULL)
		return (-1);
	if ((pf_formats->flags & FLG_ZERO) != 0 && pf_formats->pryes == 1)
		pf_formats->flags ^= FLG_ZERO;
	ft_apply_precision(pf_formats, &str);
	ft_print_str_n_width(pf_formats, str);
	if (str != NULL)
		free(str);
	return (0);
}
