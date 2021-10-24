/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_philo_born.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 18:44:46 by jodufour          #+#    #+#             */
/*   Updated: 2021/10/24 17:17:21 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include "philosophers.h"
#include "type/t_ctx.h"
#include "type/t_philo.h"
#include "enum/e_ret.h"

int	phi_philo_born(t_philo *philo, int *const ret)
{
	t_ctx *const	ctx = phi_ctx_get();
	t_lint const	nb_philo = ctx->nb_philo;
	t_lint			i;

	if (phi_now(&ctx->start))
		return (*ret = GET_TIME_OF_DAY_ERR);
	i = 0;
	while (i < nb_philo)
	{
		if (phi_now(&philo->last_meal))
			return (*ret = GET_TIME_OF_DAY_ERR);
		if (pthread_create(&philo->thread, NULL, phi_philo_routine, philo))
			return (*ret = PTHREAD_CREATE_ERR);
		++philo;
		++i;
	}
	return (*ret = SUCCESS);
}
