/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_ctx_init_nb_philo.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 22:06:33 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/08 04:07:11 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "type/t_ctx.h"
#include "enum/e_ret.h"

int	phi_ctx_init_nb_philo(char const *str, int *const ret)
{
	t_ctx *const	ctx = phi_ctx_get();

	while (phi_is_space(*str))
		++str;
	if (*str == '+')
		++str;
	while (*str == '0' && phi_is_digit(*(str + 1)))
		++str;
	ctx->nb_philo = phi_atol(str);
	if (phi_limits_check(str, ctx->nb_philo, ret))
		return (*ret);
	return (*ret = SUCCESS);
}
