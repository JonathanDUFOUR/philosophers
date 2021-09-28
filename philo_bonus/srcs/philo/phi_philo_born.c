/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_philo_born.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 18:44:46 by jodufour          #+#    #+#             */
/*   Updated: 2021/09/21 03:17:32 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include "philosophers.h"
#include "type/t_ctx.h"
#include "type/t_philo.h"
#include "enum/e_ret.h"

int	phi_philo_born(t_philo *philo)
{
	t_ctx *const	ctx = phi_ctx_get();
	t_lint const	nb_philo = phi_ctx_get()->nb_philo;
	t_lint			i;

	ctx->start = phi_now();
	if (ctx->start == -1)
		return (GET_TIME_OF_DAY_ERR);
	i = 0;
	while (i < nb_philo)
	{
		philo[i].last_meal = phi_now();
		if (philo[i].last_meal == -1)
			return (GET_TIME_OF_DAY_ERR);
		if (pthread_create(&philo[i].thread, NULL, phi_routine, philo + i))
			return (PTHREAD_CREATE_ERR);
		++i;
	}
	return (SUCCESS);
}
