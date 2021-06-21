/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_precision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: statooin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 10:29:20 by statooin          #+#    #+#             */
/*   Updated: 2020/07/28 10:29:26 by statooin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_apply_precision(t_format *pf_formats, char **str)
{
	size_t	str_len;
	char	*tmp;

	if (*str == NULL)
		return (-1);
	if (pf_formats->pryes == 1)
	{
		str_len = ft_strlen(*str);
		if (pf_formats->preci == 0 && *str[0] == '0')
		{
			*str[0] = '\0';
		}
		else if (pf_formats->preci > str_len)
		{
			tmp = ft_strnewfill(pf_formats->preci, '0');
			ft_strlcpy(&tmp[pf_formats->preci - str_len], *str, str_len + 1);
			if (*str != NULL)
				free(*str);
			*str = ft_strdup(tmp);
			if (tmp != NULL)
				free(tmp);
		}
	}
	return (1);
}
