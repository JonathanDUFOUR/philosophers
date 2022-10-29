/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_philo_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 12:34:07 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/08 03:52:32 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "type/t_ctx.h"
#include "type/t_philo.h"
#include "enum/e_state.h"

void	phi_philo_init(t_philo *philo, t_mutex *fork)
{
	t_lint const	nb_philo = phi_ctx_get()->nb_philo;
	t_lint			idx;

	idx = 0;
	while (idx < nb_philo)
	{
		pthread_mutex_init(fork + idx, NULL);
		++idx;
	}
	idx = 0;
	while (idx < nb_philo)
	{
		philo[idx].idx = idx + 1;
		philo[idx].meal_count = 0;
		philo[idx].last_meal = 0;
		philo[idx].state = THINKING;
		philo[idx].fork_right = fork + idx;
		if (idx)
			philo[idx].fork_left = fork + idx - 1;
		else
			philo[idx].fork_left = fork + nb_philo - 1;
		pthread_mutex_init(&philo[idx].access, NULL);
		++idx;
	}
}
