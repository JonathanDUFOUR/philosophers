/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_philo_suicide.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 02:30:01 by jodufour          #+#    #+#             */
/*   Updated: 2021/10/24 18:25:05 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type/t_philo.h"
#include "type/t_ctx.h"
#include "enum/e_ret.h"

static int	get_time_to_die(t_lint *const time_to_die, int *const ret)
{
	t_ctx *const	ctx = phi_ctx_get();

	if (pthread_mutex_lock(&ctx->access))
		return (*ret = MUTEX_LOCK_ERR);
	*time_to_die = ctx->time_to_die;
	if (pthread_mutex_unlock(&ctx->access))
		return (*ret = MUTEX_UNLOCK_ERR);
	return (*ret = SUCCESS);
}

int	phi_philo_suicide(t_philo *const philo, int *const ret)
{
	t_lint	time_to_die;

	if (get_time_to_die(&time_to_die, ret))
		return (*ret);
	if (phi_philo_wait(philo, time_to_die * 2 + 1, ret))
		return (*ret);
	return (*ret = SUCCESS);
}
