/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_manager_kill.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 00:59:16 by jodufour          #+#    #+#             */
/*   Updated: 2021/10/24 02:04:08 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "type/t_manager.h"
#include "type/t_ctx.h"
#include "enum/e_state.h"
#include "enum/e_ret.h"

static int	get_data(
	t_lint *const required_meals,
	t_lint *const time_to_die,
	int *const ret)
{
	t_ctx *const	ctx = phi_ctx_get();

	if (pthread_mutex_lock(&ctx->access))
		return (*ret = MUTEX_LOCK_ERR);
	*required_meals = ctx->required_meals;
	*time_to_die = ctx->time_to_die;
	if (pthread_mutex_unlock(&ctx->access))
		return (*ret = MUTEX_UNLOCK_ERR);
	return (*ret = SUCCESS);
}

static int	kill_one(
	t_philo *philo,
	t_lint i,
	t_lint *const hungry,
	int *const ret)
{
	t_lint			required_meals;
	t_lint			time_to_die;
	t_lint			now;

	if (get_data(&required_meals, &time_to_die, ret))
		return (*ret);
	if (pthread_mutex_lock(&philo[i].access))
		return (*ret = MUTEX_LOCK_ERR);
	if (phi_now(&now))
		return (*ret = GET_TIME_OF_DAY_ERR);
	*ret = SIMULATION_RUN;
	if (now - philo[i].last_meal >= time_to_die)
	{
		philo[i].state = DEAD;
		*ret = SIMULATION_STOP;
	}
	if (philo[i].meal_count < required_meals || required_meals == -1)
		++*hungry;
	if (pthread_mutex_unlock(&philo[i].access))
		return (*ret = MUTEX_UNLOCK_ERR);
	return (*ret);
}

int	phi_manager_kill(t_philo *philo, int *const ret)
{
	t_ctx *const	ctx = phi_ctx_get();
	t_lint			nb_philo;
	t_lint			hungry;
	t_lint			i;

	if (pthread_mutex_lock(&ctx->access))
		return (*ret = MUTEX_LOCK_ERR);
	nb_philo = ctx->nb_philo;
	if (pthread_mutex_unlock(&ctx->access))
		return (*ret = MUTEX_UNLOCK_ERR);
	hungry = 0;
	i = 0;
	while (i < nb_philo && kill_one(philo, i, &hungry, ret) == SIMULATION_RUN)
		++i;
	if (*ret == SIMULATION_RUN && !hungry)
		return (*ret = SIMULATION_STOP);
	return (*ret);
}
