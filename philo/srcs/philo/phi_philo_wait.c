/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_philo_wait.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 16:55:43 by jodufour          #+#    #+#             */
/*   Updated: 2021/10/24 00:38:04 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "philosophers.h"
#include "type/t_ctx.h"
#include "type/t_philo.h"
#include "enum/e_state.h"
#include "enum/e_ret.h"

static int	get_state(t_philo *const philo, t_hhuint *state, int *const ret)
{
	if (pthread_mutex_lock(&philo->access))
		return (*ret = MUTEX_LOCK_ERR);
	*state = philo->state;
	if (pthread_mutex_unlock(&philo->access))
		return (*ret = MUTEX_UNLOCK_ERR);
	return (*ret = SUCCESS);
}

int	phi_philo_wait(t_philo *const philo, t_lint msec, int *const ret)
{
	t_lint		start;
	t_lint		now;
	t_lint		waited;
	t_hhuint	state;

	if (phi_now(&start))
		return (*ret = GET_TIME_OF_DAY_ERR);
	if (phi_now(&now))
		return (*ret = GET_TIME_OF_DAY_ERR);
	if (get_state(philo, &state, ret))
		return (*ret);
	waited = now - start;
	while (state != DEAD && state != STOP && waited < msec)
	{
		if (usleep(100) == -1)
			return (*ret = USLEEP_ERR);
		if (get_state(philo, &state, ret))
			return (*ret);
		if (phi_now(&now))
			return (*ret = GET_TIME_OF_DAY_ERR);
		waited = now - start;
	}
	return (*ret = SUCCESS);
}
