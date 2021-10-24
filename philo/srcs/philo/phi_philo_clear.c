/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_philo_clear.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 14:51:08 by jodufour          #+#    #+#             */
/*   Updated: 2021/10/24 18:01:51 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "type/t_philo.h"
#include "type/t_ctx.h"
#include "enum/e_ret.h"

static int	get_nb_philo(t_lint *const nb_philo, int *const ret)
{
	t_ctx *const	ctx = phi_ctx_get();

	if (pthread_mutex_lock(&ctx->access))
		return (*ret = MUTEX_LOCK_ERR);
	*nb_philo = ctx->nb_philo;
	if (pthread_mutex_unlock(&ctx->access))
		return (*ret = MUTEX_UNLOCK_ERR);
	return (*ret = SUCCESS);
}

int	phi_philo_clear(t_philo *philo, int *const ret)
{
	t_lint	nb_philo;
	t_lint	i;

	if (get_nb_philo(&nb_philo, ret))
		return (*ret);
	i = 0;
	while (i < nb_philo)
	{
		if (pthread_mutex_destroy(&philo->access)
			|| pthread_mutex_destroy(philo->fork_right))
			return (*ret = MUTEX_DESTROY_ERR);
		memset(philo, 0, sizeof(t_philo));
		++philo;
		++i;
	}
	return (*ret = SUCCESS);
}
