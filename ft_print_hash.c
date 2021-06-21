/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hash.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: statooin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 06:01:38 by statooin          #+#    #+#             */
/*   Updated: 2020/07/29 06:08:02 by statooin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hash(t_format *pf_formats, char **str, char *hash)
{
	if (*str == NULL)
		return (-1);
	if ((pf_formats->flags & FLG_HASH) != 0)
	{
		if (pf_formats->width > ft_strlen(*str) &&
			(pf_formats->flags & FLG_ZERO) != 0)
		{
			ft_putstr_fd(hash, 1);
			pf_formats->prlen += 2;
			pf_formats->width -= 2;
		}
		else
			ft_strjoin_f(hash, *str, str);
	}
	return (1);
}
