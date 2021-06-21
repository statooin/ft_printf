/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: statooin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 13:43:55 by statooin          #+#    #+#             */
/*   Updated: 2020/07/27 13:43:58 by statooin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_string(t_format *pf_formats, char *str)
{
	if ((pf_formats->flags & FLG_ZERO) != 0 && pf_formats->pryes == 1)
		pf_formats->flags ^= FLG_ZERO;
	if (pf_formats->pryes == 1)
		if (pf_formats->preci < ft_strlen(str))
			str[pf_formats->preci] = '\0';
	ft_print_str_n_width(pf_formats, str);
	if (str != NULL)
		free(str);
	return (0);
}
