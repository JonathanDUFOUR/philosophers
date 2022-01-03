/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_philo_state_msg.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 11:53:51 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/03 15:18:50 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>
#include "philosophers.h"
#include "type/t_ctx.h"
#include "type/t_philo.h"
#include "lookup_state_msg.h"
#include "enum/e_ret.h"

static char const	*state_msg_get(t_hhuint const state)
{
	int	i;

	i = 0;
	while (g_state_msg[i].msg && state != g_state_msg[i].state)
		++i;
	return (g_state_msg[i].msg);
}

static int	state_msg_print(char const *msg, t_lint const idx, int *const ret)
{
	t_ctx *const	ctx = phi_ctx_get();
	t_lint			start;
	t_lint			now;

	if (phi_now(&now))
		return (*ret = GET_TIME_OF_DAY_ERR);
	if (pthread_mutex_lock(&ctx->access))
		return (*ret = MUTEX_LOCK_ERR);
	start = ctx->start;
	if (pthread_mutex_unlock(&ctx->access))
		return (*ret = MUTEX_UNLOCK_ERR);
	if (printf("%6li\t%3li %s\n", now - start, idx, msg) == -1)
		return (*ret = PRINTF_ERR);
	return (*ret = SUCCESS);
}

int	phi_philo_state_msg(t_philo *const philo, int *const ret)
{
	t_mutex *const	voice = phi_voice_get();
	char const		*msg;
	t_hhuint		state;
	t_lint			idx;

	if (pthread_mutex_lock(voice))
		return (*ret = MUTEX_LOCK_ERR);
	if (pthread_mutex_lock(&philo->access))
		return (*ret = MUTEX_LOCK_ERR);
	idx = philo->idx;
	state = philo->state;
	if (state == DEAD)
		philo->state = STOP;
	if (pthread_mutex_unlock(&philo->access))
		return (*ret = MUTEX_UNLOCK_ERR);
	msg = state_msg_get(state);
	if (msg && state_msg_print(msg, idx, ret))
		return (*ret);
	if (pthread_mutex_unlock(voice))
		return (*ret = MUTEX_UNLOCK_ERR);
	return (*ret = SUCCESS);
}
