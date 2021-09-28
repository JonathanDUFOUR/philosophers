/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_routine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 18:05:11 by jodufour          #+#    #+#             */
/*   Updated: 2021/09/21 08:19:42 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* DEBUG */
#include <stdio.h>

#include <stddef.h>
#include <unistd.h>
#include "philosophers.h"
#include "type/t_ctx.h"
#include "type/t_philo.h"
#include "enum/e_ret.h"

void	*phi_routine(void *param)
{
	t_ctx *const	ctx = phi_ctx_get();
	t_philo *const	philo = (t_philo *)param;
	int				ret;

	ret = SUCCESS;
	if (pthread_mutex_lock(&ctx->access))
		ret = MUTEX_LOCK_ERR;
	while (ret == SUCCESS
		&& (ctx->required_meals == -1
			|| (ctx->meal_count / ctx->nb_philo) < ctx->required_meals))
	{
		if (pthread_mutex_unlock(&ctx->access))
			ret = MUTEX_UNLOCK_ERR;
		if (ret == SUCCESS)
			ret = phi_philo_eat(philo);
		if (ret == SUCCESS)
			ret = phi_philo_sleep(philo);
		if (ret == SUCCESS)
			ret = phi_philo_think(philo);
	}
	if (pthread_mutex_unlock(&ctx->access))
		ret = MUTEX_UNLOCK_ERR;
	if (ret != SUCCESS)
		phi_err_msg(ret);
	return (NULL);
}
