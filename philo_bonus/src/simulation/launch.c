/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 02:39:42 by jodufour          #+#    #+#             */
/*   Updated: 2024/11/14 17:50:05 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simulation.h"
#include "thread_arguments.h"
#include <pthread.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

/**
 * @brief Releases the resources that won't be used
 *        by the calling child process, including the process ids
 *        of all the child processes, and the array of philosophers.
 * 
 * @param simulation A reference to the simulation data
 *        from which to release the resources.
 */
inline static void
	release_unused_resources(
		t_simulation *const simulation
	)
{
	free(simulation->philosophers);
	free(simulation->pids);
}

/**
 * @brief Terminates every child process and waits for them to finish.
 * 
 * @param pids The ids of the child processes to terminate and wait for.
 * 
 * @param number_of_pids How many elements does `pids` contain.
 * 
 * @return Always `true`.
 */
inline static bool
	terminate(
		pid_t *const pids,
		uint8_t number_of_pids
	)
{
	while (!__builtin_sub_overflow(number_of_pids, 1, &number_of_pids))
	{
		kill(pids[number_of_pids], SIGTERM);
		waitpid(pids[number_of_pids], NULL, 0);
	}
	return (true);
}

/**
 * @brief Creates one process per philosopher, with each running the
 *        philosopher's life cycle. Also creates as many thread as there are
 *        philosophers, to send the start signal to all the philosophers.
 *        Once the signal is sent, these threads are directly finished.
 * 
 * @param simulation A reference to the simulation data to use to launch it.
 * 
 * @param number_of_philosophers How many processes to create.
 * 
 * @param status A reference to the status to set if the creation fails,
 * 
 * @return `true` if a ( process | thread ) creation fails, `false` otherwise.
 */
bool
	simulation_launch(
		t_simulation *const simulation,
		uint8_t const number_of_philosophers,
		t_status *const status
	)
{
	t_philosopher	philosopher;
	uint8_t			i;

	i = 0;
	while (i < number_of_philosophers)
	{
		simulation->pids[i] = fork();
		if (simulation->pids[i] == -1 && terminate(simulation->pids, i))
			return (*status = ERR_FORK, true);
		if (simulation->pids[i] == 0)
		{
			philosopher = simulation->philosophers[i];
			release_unused_resources(simulation);
			philosopher_life_cycle(&philosopher);
			__builtin_unreachable();
		}
		++i;
	}
	return (false);
}
