/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_llong.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: statooin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 02:50:19 by statooin          #+#    #+#             */
/*   Updated: 2020/07/29 02:50:48 by statooin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format_llong(t_format *pf_formats, long long n)
{
	char	*str;
	int		sign;

	sign = n < 0 ? -1 : 1;
	if (sign == -1)
		n = -n;
	str = ft_itoa_base(n, 10);
	if (str == NULL)
		str = ft_strdup("(null)");
	if (str == NULL)
		return (-1);
	if (str[0] == '-')
		ft_strjoin_f("", &str[1], &str);
	if ((pf_formats->flags & FLG_ZERO) != 0 && pf_formats->pryes == 1)
		pf_formats->flags ^= FLG_ZERO;
	if ((pf_formats->flags & FLG_MINU) != 0
			&& (pf_formats->flags & FLG_ZERO) != 0)
		pf_formats->flags ^= FLG_ZERO;
	ft_apply_precision(pf_formats, &str);
	ft_print_signes(pf_formats, &str, sign);
	ft_print_nbr_n_width(pf_formats, &str);
	if (str != NULL)
		free(str);
	return (1);
}
