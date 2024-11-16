/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 02:32:10 by jodufour          #+#    #+#             */
/*   Updated: 2024/11/14 21:41:11 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "semaphore_names.h"
#include "simulation.h"
#include <stdlib.h>

/**
 * @brief Releases the resources allocated for the simulation,
 *        including semaphores and dynamic memory.
 * 
 * @param simulation A reference to the simulation data to clean.
 */
void
	simulation_cleanup(
		t_simulation *const simulation
	)
{
	free(simulation->philosophers);
	free(simulation->pids);
	sem_close(simulation->forks);
	sem_close(simulation->sated_philosophers);
	sem_unlink(FORKS);
	sem_unlink(SATED_PHILOSOPHERS);
}
