/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 02:39:42 by jodufour          #+#    #+#             */
/*   Updated: 2024/11/16 23:21:45 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simulation.h"

/**
 * @brief Creates one thread per philosopher, with each running the
 *        philosopher's life cycle.
 * 
 * @param simulation A reference to the simulation data to use to launch it.
 * 
 * @param number_of_philosophers The number of threads to create.
 * 
 * @return `true` if `pthread_create()` fails, `false` otherwise.
 */
bool
	simulation_launch(
		t_simulation *const simulation,
		uint8_t const number_of_philosophers
	)
{
	uint8_t	i;

	pthread_mutex_lock(&simulation->shared);
	i = 0;
	while (i < number_of_philosophers)
	{
		if (pthread_create(
				&simulation->thread_ids[i],
				NULL,
				philosopher_life_cycle,
				&simulation->philosophers[i]))
		{
			pthread_mutex_unlock(&simulation->shared);
			while (i)
				pthread_join(simulation->thread_ids[--i], NULL);
			return (true);
		}
		++i;
	}
	simulation->is_running = true;
	pthread_mutex_unlock(&simulation->shared);
	return (false);
}
