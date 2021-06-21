/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: statooin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 02:50:19 by statooin          #+#    #+#             */
/*   Updated: 2020/07/29 02:50:48 by statooin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format_int(t_format *pf_formats, int n)
{
	char	*str;
	int		sign;

	sign = n < 0 ? -1 : 1;
	if (n == -2147483648)
		str = ft_strdup("2147483648");
	else
	{
		if (sign == -1)
			n = -n;
		str = ft_itoa(n);
	}
	if (str == NULL)
		str = ft_strdup("(null)");
	if (str == NULL)
		return (-1);
	ft_apply_flags(pf_formats);
	ft_apply_precision(pf_formats, &str);
	ft_print_signes(pf_formats, &str, sign);
	ft_print_nbr_n_width(pf_formats, &str);
	if (str != NULL)
		free(str);
	return (1);
}
