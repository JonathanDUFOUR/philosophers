/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_ctx_init_nb_philo.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 22:06:33 by jodufour          #+#    #+#             */
/*   Updated: 2021/10/24 16:49:23 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "type/t_ctx.h"
#include "enum/e_ret.h"

int	phi_ctx_init_nb_philo(char const *str)
{
	t_ctx *const	ctx = phi_ctx_get();

	while (phi_is_space(*str))
		++str;
	if (*str == '+')
		++str;
	while (*str == '0' && phi_is_digit(*(str + 1)))
		++str;
	ctx->nb_philo = phi_atol(str);
	return (phi_limits_check(str, ctx->nb_philo));
}
