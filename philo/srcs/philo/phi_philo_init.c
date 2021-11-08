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
	t_lint			i;

	i = 0;
	while (i < nb_philo)
	{
		pthread_mutex_init(fork + i, NULL);
		++i;
	}
	i = 0;
	while (i < nb_philo)
	{
		philo[i].idx = i + 1;
		philo[i].meal_count = 0;
		philo[i].last_meal = 0;
		philo[i].state = THINKING;
		philo[i].fork_right = fork + i;
		if (i)
			philo[i].fork_left = fork + i - 1;
		else
			philo[i].fork_left = fork + nb_philo - 1;
		pthread_mutex_init(&philo[i].access, NULL);
		++i;
	}
}
