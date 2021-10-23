/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_manager_stop.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 02:12:41 by jodufour          #+#    #+#             */
/*   Updated: 2021/10/24 00:53:02 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type/t_ctx.h"
#include "type/t_manager.h"
#include "enum/e_state.h"
#include "enum/e_ret.h"

static int	stop_one(t_philo *philo, t_lint i, int *const ret)
{
	if (pthread_mutex_lock(&philo[i].access))
		return (*ret = MUTEX_LOCK_ERR);
	if (philo[i].state != DEAD)
		philo[i].state = STOP;
	if (pthread_mutex_unlock(&philo[i].access))
		return (*ret = MUTEX_UNLOCK_ERR);
	return (*ret = SUCCESS);
}

int	phi_manager_stop(t_philo *philo, int *const ret)
{
	t_ctx *const	ctx = phi_ctx_get();
	t_lint			nb_philo;
	t_lint			i;

	if (pthread_mutex_lock(&ctx->access))
		return (*ret = MUTEX_LOCK_ERR);
	nb_philo = ctx->nb_philo;
	if (pthread_mutex_unlock(&ctx->access))
		return (*ret = MUTEX_UNLOCK_ERR);
	i = 0;
	while (i < nb_philo && !stop_one(philo, i, ret))
		++i;
	return (*ret);
}
