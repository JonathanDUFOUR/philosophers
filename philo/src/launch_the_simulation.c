/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_the_simulation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 02:39:42 by jodufour          #+#    #+#             */
/*   Updated: 2024/11/06 20:12:06 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal_functions.h"

/**
 * @brief Creates one thread per philosopher, with each running the
 *        philosopher's life cycle.
 * 
 * @param simulation A reference to the simulation data to use to launch it.
 * 
 * @param number_of_philosophers The number of threads to create.
 * 
 * @param status A reference to the status to set if a thread creation fails.
 * 
 * @return `true` if a thread creation fails, `false` otherwise.
 */
bool
	launch_the_simulation(
		t_simulation *const simulation,
		uint8_t const number_of_philosophers,
		t_status *const status
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
				philosopher_routine,
				&simulation->philosophers[i]))
		{
			pthread_mutex_unlock(&simulation->shared);
			while (i)
				pthread_join(simulation->thread_ids[--i], NULL);
			return (*status = ERR_PTHREAD_CREATE, true);
		}
		++i;
	}
	simulation->is_running = true;
	pthread_mutex_unlock(&simulation->shared);
	return (false);
}
