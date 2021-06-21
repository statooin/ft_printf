/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: statooin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 10:29:20 by statooin          #+#    #+#             */
/*   Updated: 2020/07/28 10:29:26 by statooin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_apply_flags(t_format *pf_formats)
{
	if ((pf_formats->flags & FLG_ZERO) != 0 && pf_formats->pryes == 1)
		pf_formats->flags ^= FLG_ZERO;
	if ((pf_formats->flags & FLG_MINU) != 0
			&& (pf_formats->flags & FLG_ZERO) != 0)
		pf_formats->flags ^= FLG_ZERO;
	return (1);
}
