/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_philo_state_msg.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 11:53:51 by jodufour          #+#    #+#             */
/*   Updated: 2021/10/17 23:15:21 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>
#include "philosophers.h"
#include "type/t_ctx.h"
#include "type/t_philo.h"
#include "type/t_voice.h"
#include "state_msg_lookup.h"
#include "enum/e_ret.h"

static char const	*state_msg_get(int state)
{
	int	i;

	i = 0;
	while (g_state_msg[i].msg && state != g_state_msg[i].state)
		++i;
	return (g_state_msg[i].msg);
}

int	phi_philo_state_msg(t_philo *philo)
{
	t_ctx *const	ctx = phi_ctx_get();
	char const		*msg;
	t_huint			idx;
	t_lint			now;

	if (pthread_mutex_lock(&philo->access))
		return (MUTEX_LOCK_ERR);
	idx = philo->idx;
	msg = state_msg_get(philo->state);
	if (pthread_mutex_unlock(&philo->access))
		return (MUTEX_UNLOCK_ERR);
	if (pthread_mutex_lock(&ctx->access))
		return (MUTEX_LOCK_ERR);
	now = phi_now();
	if (now == -1)
		return (GET_TIME_OF_DAY_ERR);
	if (msg)
		printf("%6li %hu %s\n", now - ctx->start, idx, msg);
	if (pthread_mutex_unlock(&ctx->access))
		return (MUTEX_UNLOCK_ERR);
	return (SUCCESS);
}
