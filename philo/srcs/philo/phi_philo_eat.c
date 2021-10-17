/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_philo_eat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 18:39:51 by jodufour          #+#    #+#             */
/*   Updated: 2021/10/17 23:52:09 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "type/t_ctx.h"
#include "type/t_philo.h"
#include "enum/e_state.h"
#include "enum/e_ret.h"

static int	lock_forks(t_philo *const philo, t_mutex *fork0, t_mutex *fork1)
{
	int	ret;

	if (pthread_mutex_lock(fork0))
		return (MUTEX_LOCK_ERR);
	if (pthread_mutex_lock(&philo->access))
		return (MUTEX_LOCK_ERR);
	if (philo->state == THINKING)
		philo->state = TOOK_FORK;
	if (pthread_mutex_unlock(&philo->access))
		return (MUTEX_UNLOCK_ERR);
	ret = phi_philo_state_msg(philo);
	if (ret != SUCCESS)
		return (ret);
	if (fork0 == fork1)
		return (phi_philo_suicide(philo));
	if (pthread_mutex_lock(fork1))
		return (MUTEX_LOCK_ERR);
	puts("coucou");
	return (phi_philo_state_msg(philo));
}

static int	unlock_forks(t_mutex *fork0, t_mutex *fork1)
{
	if (pthread_mutex_unlock(fork0))
		return (MUTEX_UNLOCK_ERR);
	if (fork0 != fork1 && pthread_mutex_unlock(fork1))
		return (MUTEX_UNLOCK_ERR);
	return (SUCCESS);
}

static int	update_philo(t_philo *const philo)
{
	t_lint	now;

	now = phi_now();
	if (now == -1)
		return (GET_TIME_OF_DAY_ERR);
	if (pthread_mutex_lock(&philo->access))
		return (MUTEX_LOCK_ERR);
	if (philo->state == TOOK_FORK)
	{
		philo->state = EATING;
		philo->last_meal = now;
		++philo->meal_count;
	}
	if (pthread_mutex_unlock(&philo->access))
		return (MUTEX_UNLOCK_ERR);
	return (phi_philo_state_msg(philo));
}

int	phi_philo_eat(t_philo *const philo)
{
	t_ctx *const	ctx = phi_ctx_get();
	t_lint			time_to_eat;
	int				ret;

	if (philo->idx % 2)
		ret = lock_forks(philo, philo->fork_right, philo->fork_left);
	else
		ret = lock_forks(philo, philo->fork_left, philo->fork_right);
	if (ret == SUCCESS)
		ret = update_philo(philo);
	if (ret == SUCCESS && pthread_mutex_lock(&ctx->access))
		return (MUTEX_LOCK_ERR);
	if (ret == SUCCESS)
		time_to_eat = ctx->time_to_eat;
	if (ret == SUCCESS && pthread_mutex_unlock(&ctx->access))
		return (MUTEX_UNLOCK_ERR);
	if (ret == SUCCESS)
		ret = phi_philo_wait(philo, time_to_eat);
	if (ret == SUCCESS)
		ret = unlock_forks(philo->fork_right, philo->fork_left);
	return (ret);
}
