/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_manager_routine.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 20:57:46 by jodufour          #+#    #+#             */
/*   Updated: 2021/10/24 16:53:19 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "philosophers.h"
#include "type/t_ctx.h"
#include "type/t_manager.h"
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

static void	*quit(int const ret)
{
	if (ret != SUCCESS)
		phi_err_msg(ret);
	return (NULL);
}

void	*phi_manager_routine(void *param)
{
	t_manager *const	manager = (t_manager *)param;
	int					ret;

	if (start_signal(&ret))
		return (quit(ret));
	while (phi_manager_kill(manager->philo, &ret) == SIMULATION_RUN)
		if (usleep(100) == -1)
			return (quit(USLEEP_ERR));
	if (ret == SIMULATION_STOP)
		phi_manager_stop(manager->philo, &ret);
	return (quit(ret));
}
