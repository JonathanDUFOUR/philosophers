/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_the_simulation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 02:32:10 by jodufour          #+#    #+#             */
/*   Updated: 2024/11/06 20:30:40 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simulation.h"
#include <stdlib.h>

/**
 * @brief Releases the resources allocated for the simulation, such as
 *        the mutexes, and the allocated memory for the forks, philosophers,
 *        and thread ids.
 * 
 * @param simulation A reference to the simulation data to clean.
 * 
 * @param n How many forks, philosophers, and thread ids
 *        the simulation contains.
 */
void
	clean_the_simulation(
		t_simulation *const simulation,
		uint8_t n
	)
{
	pthread_mutex_destroy(&simulation->shared);
	while (!__builtin_sub_overflow(n, 1, &n))
	{
		pthread_mutex_destroy(&simulation->forks[n]);
		pthread_mutex_destroy(&simulation->philosophers[n].meals);
	}
	free(simulation->forks);
	free(simulation->philosophers);
	free(simulation->thread_ids);
}
