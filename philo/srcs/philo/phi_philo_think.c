/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_philo_think.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 18:43:10 by jodufour          #+#    #+#             */
/*   Updated: 2021/10/17 23:53:38 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "type/t_ctx.h"
#include "type/t_philo.h"
#include "enum/e_ret.h"
#include "enum/e_state.h"

int	phi_philo_think(t_philo *const philo)
{
	t_ctx *const	ctx = phi_ctx_get();
	t_lint			time_to_eat;
	t_lint			time_to_sleep;
	int				ret;

	if (pthread_mutex_lock(&philo->access))
		return (MUTEX_LOCK_ERR);
	if (philo->state == SLEEPING)
		philo->state = THINKING;
	if (pthread_mutex_unlock(&philo->access))
		return (MUTEX_UNLOCK_ERR);
	ret = phi_philo_state_msg(philo);
	if (pthread_mutex_lock(&ctx->access))
		return (MUTEX_LOCK_ERR);
	time_to_eat = ctx->time_to_eat;
	time_to_sleep = ctx->time_to_sleep;
	if (pthread_mutex_unlock(&ctx->access))
		return (MUTEX_UNLOCK_ERR);
	if (time_to_eat > time_to_sleep)
		ret = phi_philo_wait(philo, time_to_eat - time_to_sleep);
	return (ret);
}
