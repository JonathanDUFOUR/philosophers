/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_ctx_init_nb_philo.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 22:06:33 by jodufour          #+#    #+#             */
/*   Updated: 2021/09/15 18:02:28 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "type/t_ctx.h"
#include "enum/e_ret.h"

int	phi_ctx_init_nb_philo(char const *s)
{
	t_ctx *const	ctx = phi_ctx_get();

	while (phi_is_space(*s))
		++s;
	if (*s == '+')
		++s;
	while (*s == '0' && phi_is_digit(*(s + 1)))
		++s;
	ctx->nb_philo = phi_atol(s);
	return (phi_limits_check(s, ctx->nb_philo));
}
