/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_philo_sleep.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 18:41:33 by jodufour          #+#    #+#             */
/*   Updated: 2021/10/24 00:14:54 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "philosophers.h"
#include "type/t_ctx.h"
#include "type/t_philo.h"
#include "enum/e_ret.h"
#include "enum/e_state.h"

int	phi_philo_sleep(t_philo *const philo, int *const ret)
{
	t_ctx *const	ctx = phi_ctx_get();
	t_lint			time_to_sleep;

	if (pthread_mutex_lock(&philo->access))
		return (*ret = MUTEX_LOCK_ERR);
	if (philo->state == EATING)
		philo->state = SLEEPING;
	if (pthread_mutex_unlock(&philo->access))
		return (*ret = MUTEX_UNLOCK_ERR);
	if (phi_philo_state_msg(philo, ret))
		return (*ret);
	if (pthread_mutex_lock(&ctx->access))
		return (*ret = MUTEX_LOCK_ERR);
	time_to_sleep = ctx->time_to_sleep;
	if (pthread_mutex_unlock(&ctx->access))
		return (*ret = MUTEX_UNLOCK_ERR);
	if (phi_philo_wait(philo, time_to_sleep, ret))
		return (*ret);
	return (*ret = SUCCESS);
}
