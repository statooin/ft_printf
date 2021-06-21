/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: statooin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 05:58:56 by statooin          #+#    #+#             */
/*   Updated: 2020/07/29 05:58:59 by statooin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format_n(t_format *pf_formats)
{
	int *n;

	n = va_arg(pf_formats->argus, int *);
	*n = pf_formats->prlen;
	return (1);
}
