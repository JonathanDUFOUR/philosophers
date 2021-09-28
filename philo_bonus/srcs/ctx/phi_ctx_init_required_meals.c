/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_ctx_init_required_meals.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 03:45:01 by jodufour          #+#    #+#             */
/*   Updated: 2021/09/20 16:50:14 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "type/t_ctx.h"
#include "enum/e_ret.h"

int	phi_ctx_init_required_meals(char const *s)
{
	t_ctx *const	ctx = phi_ctx_get();

	if (!s)
		return (SUCCESS);
	while (phi_is_space(*s))
		++s;
	if (*s == '+')
		++s;
	while (*s == '0' && phi_is_digit(*(s + 1)))
		++s;
	ctx->required_meals = phi_atol(s);
	return (phi_limits_check(s, ctx->required_meals));
}
