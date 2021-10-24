/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_manager_stop.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 02:12:41 by jodufour          #+#    #+#             */
/*   Updated: 2021/10/24 17:59:53 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type/t_ctx.h"
#include "type/t_manager.h"
#include "enum/e_state.h"
#include "enum/e_ret.h"

static int	get_nb_philo(t_lint *const nb_philo, int *const ret)
{
	t_ctx *const	ctx = phi_ctx_get();

	if (pthread_mutex_lock(&ctx->access))
		return (*ret = MUTEX_LOCK_ERR);
	*nb_philo = ctx->nb_philo;
	if (pthread_mutex_unlock(&ctx->access))
		return (*ret = MUTEX_UNLOCK_ERR);
	return (*ret = SUCCESS);
}

static int	stop_one(t_philo *const philo, int *const ret)
{
	if (pthread_mutex_lock(&philo->access))
		return (*ret = MUTEX_LOCK_ERR);
	if (philo->state != DEAD)
		philo->state = STOP;
	if (pthread_mutex_unlock(&philo->access))
		return (*ret = MUTEX_UNLOCK_ERR);
	return (*ret = SUCCESS);
}

int	phi_manager_stop(t_philo *philo, int *const ret)
{
	t_lint	nb_philo;
	t_lint	i;

	if (get_nb_philo(&nb_philo, ret))
		return (*ret);
	i = 0;
	while (i < nb_philo && stop_one(philo + i, ret) == SUCCESS)
		++i;
	return (*ret);
}
