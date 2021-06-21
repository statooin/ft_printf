/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_minus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: statooin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 10:29:20 by statooin          #+#    #+#             */
/*   Updated: 2020/07/29 03:27:55 by statooin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_minus(t_format *pf_formats, char **str)
{
	if (*str == NULL)
		return (-1);
	ft_putchar_fd('-', 1);
	pf_formats->prlen++;
	ft_strjoin_f(&str[0][1], "", str);
	pf_formats->width--;
	return (1);
}
