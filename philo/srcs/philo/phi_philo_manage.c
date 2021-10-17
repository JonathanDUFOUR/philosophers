/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_philo_manage.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 20:57:46 by jodufour          #+#    #+#             */
/*   Updated: 2021/10/17 21:50:25 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "type/t_ctx.h"
#include "type/t_philo.h"
#include "enum/e_state.h"
#include "enum/e_ret.h"

static int	is_dying(t_philo *const philo, t_lint time_to_die)
{
	t_lint	now;

	now = phi_now();
	if (now == -1)
		return (GET_TIME_OF_DAY_ERR);
	if (philo->last_meal - now >= time_to_die)
	{
		philo->state = DEAD;
		return (SIMULATION_STOP);
	}
	return (SIMULATION_RUN);
}

static int	check_death(t_philo *philo)
{
	t_ctx *const	ctx = phi_ctx_get();
	t_lint			time_to_die;
	t_lint			nb_philo;
	t_lint			i;
	int				ret;

	if (pthread_mutex_lock(&ctx->access))
		return (MUTEX_LOCK_ERR);
	time_to_die = ctx->time_to_die;
	nb_philo = ctx->nb_philo;
	if (pthread_mutex_unlock(&ctx->access))
		return (MUTEX_UNLOCK_ERR);
	ret = SIMULATION_RUN;
	i = 0;
	while (ret == SIMULATION_RUN && i < nb_philo)
	{
		if (pthread_mutex_lock(&philo[i].access))
			return (MUTEX_LOCK_ERR);
		ret = is_dying(philo + i, time_to_die);
		if (pthread_mutex_unlock(&philo[i].access))
			return (MUTEX_UNLOCK_ERR);
		++i;
	}
	return (ret);
}

static int	check_meal_count(t_philo *philo)
{
	return (SIMULATION_RUN);
}

int	phi_philo_manage(t_philo *philo)
{
	int	ret;

	ret = SIMULATION_RUN;
	while (ret == SIMULATION_RUN)
	{
		ret = check_death(philo);
		if (ret == SIMULATION_RUN)
			ret = check_meal_count(philo);
	}
	if (ret == SIMULATION_STOP)
		return (phi_philo_stop(philo));
	return (ret);
}
