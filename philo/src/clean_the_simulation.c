/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_the_simulation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 02:32:10 by jodufour          #+#    #+#             */
/*   Updated: 2024/10/30 22:18:05 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simulation.h"
#include <stdlib.h>

/**
 * @brief Frees the memory allocated for the forks, philosophers, and threads.
 * 
 * @param simulation A reference to the simulation data to clean.
 * 
 * @param n The number of forks and philosophers in the simulation.
 */
void
	clean_the_simulation(
		t_simulation *const simulation,
		uint8_t n
	)
{
	pthread_mutex_destroy(&simulation->common);
	while (!__builtin_sub_overflow(n, 1, &n))
	{
		pthread_mutex_destroy(&simulation->forks[n]);
		pthread_mutex_destroy(&simulation->philosophers[n].meals);
	}
	free(simulation->forks);
	free(simulation->philosophers);
	free(simulation->threads);
}
