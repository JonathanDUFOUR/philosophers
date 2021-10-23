/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_philo_routine.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 20:21:26 by jodufour          #+#    #+#             */
/*   Updated: 2021/10/24 01:03:37 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "philosophers.h"
#include "type/t_ctx.h"
#include "type/t_philo.h"
#include "enum/e_state.h"
#include "enum/e_ret.h"

static int	start_signal(int *const ret)
{
	t_ctx *const	ctx = phi_ctx_get();

	if (pthread_mutex_lock(&ctx->access))
		return (*ret = MUTEX_LOCK_ERR);
	if (pthread_mutex_unlock(&ctx->access))
		return (*ret = MUTEX_UNLOCK_ERR);
	return (*ret = SUCCESS);
}

static int	get_state(t_philo *const philo, t_hhuint *state, int *const ret)
{
	if (pthread_mutex_lock(&philo->access))
		return (*ret = MUTEX_LOCK_ERR);
	*state = philo->state;
	if (pthread_mutex_unlock(&philo->access))
		return (*ret = MUTEX_UNLOCK_ERR);
	return (*ret = SUCCESS);
}

static void	*quit(int const ret)
{
	if (ret != SUCCESS)
		phi_err_msg(ret);
	return (NULL);
}

void	*phi_philo_routine(void *param)
{
	t_philo *const	philo = (t_philo *)param;
	t_hhuint		state;
	int				ret;

	if (start_signal(&ret))
		return (quit(ret));
	if (get_state(philo, &state, &ret))
		return (quit(ret));
	while (state != DEAD && state != STOP)
		if (phi_philo_eat(philo, &ret)
			|| phi_philo_sleep(philo, &ret)
			|| phi_philo_think(philo, &ret)
			|| get_state(philo, &state, &ret))
			return (quit(ret));
	if (phi_philo_state_msg(philo, &ret))
		return (quit(ret));
	return (quit(SUCCESS));
}
