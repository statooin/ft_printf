/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: statooin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 13:44:25 by statooin          #+#    #+#             */
/*   Updated: 2020/07/27 13:44:31 by statooin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format_string(t_format *pf_formats, int take_arg)
{
	char *str;

	str = NULL;
	if (take_arg == 1)
	{
		str = va_arg(pf_formats->argus, char *);
		if (str != NULL)
			str = ft_strdup(str);
		if (str == NULL)
			str = ft_strdup("(null)");
	}
	else
		str = ft_strdup("%");
	if (str == NULL)
		return (-1);
	ft_print_string(pf_formats, str);
	return (0);
}
