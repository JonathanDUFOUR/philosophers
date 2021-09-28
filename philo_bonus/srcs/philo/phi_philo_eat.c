/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_philo_eat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 18:39:51 by jodufour          #+#    #+#             */
/*   Updated: 2021/09/21 08:09:02 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "philosophers.h"
#include "type/t_ctx.h"
#include "type/t_philo.h"
#include "enum/e_state.h"
#include "enum/e_ret.h"

static int	lock_forks(t_philo *philo, t_fork *fork0, t_fork *fork1)
{
	int	ret;

	if (pthread_mutex_lock(fork0))
		return (MUTEX_LOCK_ERR);
	philo->state = TOOK_FORK;
	ret = phi_philo_state_msg(philo);
	if (ret != SUCCESS)
		return (ret);
	if (fork0 == fork1)
		return (phi_philo_wait(philo, phi_ctx_get()->time_to_die * 2 + 1));
	if (pthread_mutex_lock(fork1))
		return (MUTEX_LOCK_ERR);
	return (phi_philo_state_msg(philo));
}

static int	unlock_forks(t_fork *fork0, t_fork *fork1)
{
	if (pthread_mutex_unlock(fork0))
		return (MUTEX_UNLOCK_ERR);
	if (pthread_mutex_unlock(fork1))
		return (MUTEX_UNLOCK_ERR);
	return (SUCCESS);
}

static int	update_meal_counts(t_philo *philo, t_ctx *const ctx)
{
	if (pthread_mutex_lock(&ctx->access))
		return (MUTEX_LOCK_ERR);
	if (philo->meal_count < ctx->required_meals)
	{
		++philo->meal_count;
		++ctx->meal_count;
	}
	if (pthread_mutex_unlock(&ctx->access))
		return (MUTEX_UNLOCK_ERR);
	return (SUCCESS);
}

int	phi_philo_eat(t_philo *philo)
{
	t_ctx *const	ctx = phi_ctx_get();
	int				ret;

	if (philo->idx % 2)
		ret = lock_forks(philo, philo->fork_right, philo->fork_left);
	else
		ret = lock_forks(philo, philo->fork_left, philo->fork_right);
	if (ret == SUCCESS)
	{
		philo->state = EATING;
		philo->last_meal = phi_now();
		if (philo->last_meal == -1)
			ret = GET_TIME_OF_DAY_ERR;
		else
			ret = phi_philo_state_msg(philo);
	}
	if (ret == SUCCESS)
		ret = phi_philo_wait(philo, ctx->time_to_eat);
	if (ret == SUCCESS)
		ret = unlock_forks(philo->fork_right, philo->fork_left);
	if (ret == SUCCESS)
		ret = update_meal_counts(philo, ctx);
	return (ret);
}
