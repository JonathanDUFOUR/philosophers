/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_ctx_init_time_to_eat.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 01:54:31 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/08 04:09:35 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "type/t_ctx.h"
#include "enum/e_ret.h"

int	phi_ctx_init_time_to_eat(char const *str, int *const ret)
{
	t_ctx *const	ctx = phi_ctx_get();

	while (phi_is_space(*str))
		++str;
	if (*str == '+')
		++str;
	while (*str == '0' && phi_is_digit(*(str + 1)))
		++str;
	ctx->time_to_eat = phi_atol(str);
	if (phi_limits_check(str, ctx->time_to_eat, ret))
		return (*ret);
	return (*ret = SUCCESS);
}
