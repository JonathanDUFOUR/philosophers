/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_format_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 00:08:33 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/08 04:04:04 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "enum/e_ret.h"

int	phi_format_check(char const **av, int *const ret)
{
	char const	*ptr;

	while (*++av)
	{
		ptr = *av;
		while (phi_is_space(*ptr))
			++ptr;
		if (*ptr == '+')
			++ptr;
		while (phi_is_digit(*ptr))
			++ptr;
		if (*ptr)
			return (*ret = FORMAT_ERR);
	}
	return (*ret = SUCCESS);
}
