/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_ctx_init_time_to_die.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 01:49:02 by jodufour          #+#    #+#             */
/*   Updated: 2021/09/15 18:02:47 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "type/t_ctx.h"
#include "enum/e_ret.h"

int	phi_ctx_init_time_to_die(char const *s)
{
	t_ctx *const	ctx = phi_ctx_get();

	while (phi_is_space(*s))
		++s;
	if (*s == '+')
		++s;
	while (*s == '0' && phi_is_digit(*(s + 1)))
		++s;
	ctx->time_to_die = phi_atol(s);
	return (phi_limits_check(s, ctx->time_to_die));
}
