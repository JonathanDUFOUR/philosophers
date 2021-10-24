/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_philo_think.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 18:43:10 by jodufour          #+#    #+#             */
/*   Updated: 2021/10/24 03:33:19 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "type/t_ctx.h"
#include "type/t_philo.h"
#include "enum/e_ret.h"
#include "enum/e_state.h"

int	phi_philo_think(t_philo *const philo, int *const ret)
{
	t_ctx *const	ctx = phi_ctx_get();
	t_lint			time_to_eat;
	t_lint			time_to_sleep;

	if (pthread_mutex_lock(&philo->access))
		return (*ret = MUTEX_LOCK_ERR);
	if (philo->state == SLEEPING)
		philo->state = THINKING;
	if (pthread_mutex_unlock(&philo->access))
		return (*ret = MUTEX_UNLOCK_ERR);
	if (phi_philo_state_msg(philo, ret))
		return (*ret);
	if (pthread_mutex_lock(&ctx->access))
		return (*ret = MUTEX_LOCK_ERR);
	time_to_eat = ctx->time_to_eat;
	time_to_sleep = ctx->time_to_sleep;
	if (pthread_mutex_unlock(&ctx->access))
		return (*ret = MUTEX_UNLOCK_ERR);
	if (time_to_eat > time_to_sleep)
		return (phi_philo_wait(philo, time_to_eat - time_to_sleep, ret));
	return (*ret = SUCCESS);
}
