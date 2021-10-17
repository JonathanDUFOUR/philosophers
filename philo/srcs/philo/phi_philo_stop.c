/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_philo_stop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 22:51:38 by jodufour          #+#    #+#             */
/*   Updated: 2021/10/17 09:55:07 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type/t_ctx.h"
#include "type/t_philo.h"
#include "enum/e_state.h"
#include "enum/e_ret.h"

int	phi_philo_stop(t_philo *philo)
{
	t_ctx *const	ctx = phi_ctx_get();
	t_lint			i;

	if (pthread_mutex_lock(&ctx->access))
		return (MUTEX_LOCK_ERR);
	i = 0;
	while (i < ctx->nb_philo)
	{
		if (pthread_mutex_lock(&philo[i].access))
			return (MUTEX_LOCK_ERR);
		if (philo[i].state != DEAD)
			philo[i].state = STOP;
		if (pthread_mutex_unlock(&philo[i].access))
			return (MUTEX_UNLOCK_ERR);
		++i;
	}
	if (pthread_mutex_unlock(&ctx->access))
		return (MUTEX_UNLOCK_ERR);
	return (SUCCESS);
}
