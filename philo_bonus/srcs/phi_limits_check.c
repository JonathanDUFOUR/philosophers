/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_limits_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 01:15:15 by jodufour          #+#    #+#             */
/*   Updated: 2021/09/20 16:48:56 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "philosophers.h"
#include "type/t_ctx.h"
#include "enum/e_ret.h"

int	phi_limits_check(char const *s, t_lint nb)
{
	char const	*ptr = s;
	char		check[20];
	int			len;

	while (phi_is_digit(*ptr))
		++ptr;
	if ((ptr - s) > 19)
		return (LIMITS_ERR);
	len = phi_lintlen(nb);
	check[len] = 0;
	while (len--)
	{
		check[len] = nb % 10 + '0';
		nb /= 10;
	}
	if (phi_strcmp(s, check))
		return (LIMITS_ERR);
	return (SUCCESS);
}
