/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_run.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 02:18:32 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/08 04:14:21 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "philosophers.h"
#include "type/t_ctx.h"
#include "type/t_manager.h"
#include "enum/e_ret.h"

static int	clean_quit(t_philo *philo, t_mutex *fork, int const ret)
{
	phi_memdel(&philo);
	phi_memdel(&fork);
	return (ret);
}

static int	join_all(t_philo *philo, t_lint const nb_philo, int *const ret)
{
	t_manager *const	manager = phi_manager_get();
	t_lint				i;

	if (pthread_join(manager->thread, NULL))
		return (*ret = PTHREAD_JOIN_ERR);
	i = 0;
	while (i < nb_philo)
	{
		if (pthread_join(philo[i].thread, NULL))
			return (*ret = PTHREAD_JOIN_ERR);
		++i;
	}
	return (*ret = SUCCESS);
}

int	phi_run(int *const ret)
{
	t_ctx *const	ctx = phi_ctx_get();
	t_lint const	nb_philo = ctx->nb_philo;
	t_philo			*philo;
	t_mutex			*fork;

	philo = malloc(nb_philo * sizeof(t_philo));
	if (!philo)
		return (*ret = MALLOC_ERR);
	fork = malloc(nb_philo * sizeof(t_mutex));
	if (!fork)
		return (*ret = clean_quit(philo, fork, MALLOC_ERR));
	phi_manager_init(philo, fork);
	if (pthread_mutex_lock(&ctx->access))
		return (*ret = clean_quit(philo, fork, MUTEX_LOCK_ERR));
	if (phi_manager_born(philo, ret))
		return (clean_quit(philo, fork, *ret));
	if (pthread_mutex_unlock(&ctx->access))
		return (*ret = clean_quit(philo, fork, MUTEX_UNLOCK_ERR));
	if (join_all(philo, nb_philo, ret)
		|| phi_voice_clear(ret)
		|| phi_philo_clear(philo, ret)
		|| phi_ctx_clear(ret))
		return (clean_quit(philo, fork, *ret));
	return (*ret = clean_quit(philo, fork, SUCCESS));
}
