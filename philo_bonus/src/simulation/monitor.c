/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 23:50:35 by jodufour          #+#    #+#             */
/*   Updated: 2024/11/14 16:47:42 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simulation.h"
#include <signal.h>
#include <stddef.h>
#include <sys/wait.h>

/**
 * @brief Monitors the number of sated philosophers, and stops the simulation
 *        when every philosopher is sated.
 * 
 * @param simulation A reference to the simulation data to use to monitor it.
 * 
 * @param number_of_philosophers How many philosophers are in the simulation.
 */
void
	simulation_monitor(
		t_simulation *const simulation,
		uint8_t number_of_philosophers
	)
{
	uint8_t	number_of_hungry_philosophers;

	number_of_hungry_philosophers = number_of_philosophers;
	while (!__builtin_sub_overflow(
			number_of_hungry_philosophers, 1, &number_of_hungry_philosophers))
		sem_wait(simulation->sated_philosophers);
	while (!__builtin_sub_overflow(
			number_of_philosophers, 1, &number_of_philosophers))
	{
		kill(simulation->pids[number_of_philosophers], SIGTERM);
		waitpid(simulation->pids[number_of_philosophers], NULL, 0);
	}
}
