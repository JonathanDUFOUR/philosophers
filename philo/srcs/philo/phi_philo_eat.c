/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_philo_eat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 18:39:51 by jodufour          #+#    #+#             */
/*   Updated: 2021/10/24 18:10:02 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "type/t_ctx.h"
#include "type/t_philo.h"
#include "enum/e_state.h"
#include "enum/e_ret.h"

static int	lock_forks(
	t_philo *const philo,
	t_mutex *const fork0,
	t_mutex *const fork1,
	int *const ret)
{
	if (pthread_mutex_lock(fork0))
		return (*ret = MUTEX_LOCK_ERR);
	if (pthread_mutex_lock(&philo->access))
		return (*ret = MUTEX_LOCK_ERR);
	if (philo->state == THINKING)
		philo->state = TOOK_FORK;
	if (pthread_mutex_unlock(&philo->access))
		return (*ret = MUTEX_UNLOCK_ERR);
	if (phi_philo_state_msg(philo, ret))
		return (*ret);
	if (fork0 == fork1)
		return (phi_philo_suicide(philo, ret));
	if (pthread_mutex_lock(fork1))
		return (*ret = MUTEX_LOCK_ERR);
	if (phi_philo_state_msg(philo, ret))
		return (*ret);
	return (*ret = SUCCESS);
}

static int	unlock_forks(
	t_mutex *const fork0,
	t_mutex *const fork1,
	int *const ret)
{
	if (pthread_mutex_unlock(fork0))
		return (*ret = MUTEX_UNLOCK_ERR);
	if (fork0 != fork1 && pthread_mutex_unlock(fork1))
		return (*ret = MUTEX_UNLOCK_ERR);
	return (*ret = SUCCESS);
}

static int	update_philo(t_philo *const philo, int *const ret)
{
	t_lint	now;

	if (phi_now(&now))
		return (*ret = GET_TIME_OF_DAY_ERR);
	if (pthread_mutex_lock(&philo->access))
		return (*ret = MUTEX_LOCK_ERR);
	if (philo->state == TOOK_FORK)
	{
		philo->state = EATING;
		philo->last_meal = now;
		++philo->meal_count;
	}
	if (pthread_mutex_unlock(&philo->access))
		return (*ret = MUTEX_UNLOCK_ERR);
	if (phi_philo_state_msg(philo, ret))
		return (*ret);
	return (*ret = SUCCESS);
}

static int	get_time_to_eat(t_lint *const time_to_eat, int *const ret)
{
	t_ctx *const	ctx = phi_ctx_get();

	if (pthread_mutex_lock(&ctx->access))
		return (*ret = MUTEX_LOCK_ERR);
	*time_to_eat = ctx->time_to_eat;
	if (pthread_mutex_unlock(&ctx->access))
		return (*ret = MUTEX_UNLOCK_ERR);
	return (*ret = SUCCESS);
}

int	phi_philo_eat(t_philo *const philo, int *const ret)
{
	t_lint	time_to_eat;

	if ((philo->idx % 2)
		&& lock_forks(philo, philo->fork_right, philo->fork_left, ret))
		return (*ret);
	else if (!(philo->idx % 2)
		&& lock_forks(philo, philo->fork_left, philo->fork_right, ret))
		return (*ret);
	if (update_philo(philo, ret) || get_time_to_eat(&time_to_eat, ret))
		return (*ret);
	if (phi_philo_wait(philo, time_to_eat, ret))
		return (*ret);
	if (unlock_forks(philo->fork_right, philo->fork_left, ret))
		return (*ret);
	return (*ret = SUCCESS);
}
