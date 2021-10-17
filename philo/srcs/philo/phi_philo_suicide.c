/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_philo_suicide.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 13:21:09 by jodufour          #+#    #+#             */
/*   Updated: 2021/10/17 23:55:39 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "type/t_ctx.h"
#include "type/t_philo.h"
#include "enum/e_ret.h"

int	phi_philo_suicide(t_philo *const philo)
{
	t_ctx *const	ctx = phi_ctx_get();
	int				ret;

	if (pthread_mutex_lock(&ctx->access))
		return (MUTEX_LOCK_ERR);
	ret = phi_philo_wait(philo, ctx->time_to_die * 2 + 1);
	if (pthread_mutex_unlock(&ctx->access))
		return (MUTEX_UNLOCK_ERR);
	return (ret);
}
