/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 23:56:55 by jodufour          #+#    #+#             */
/*   Updated: 2024/11/14 21:28:15 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "semaphore_names.h"
#include "simulation.h"
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>

/**
 * @brief Allocates memory for the philosophers and the process ids.
 *
 * @param simulation A reference to the simulation data
 *        to save the resulting addresses in.
 *
 * @param n How many philosophers and process ids to allocate memory for.
 *
 * @return `true` if `malloc()` fails, `false` otherwise.
 */
inline static bool
	allocate(
		t_simulation *const simulation,
		uint8_t const n
	)
{
	simulation->philosophers = malloc(n * sizeof(*simulation->philosophers));
	simulation->pids = malloc(n * sizeof(*simulation->pids));
	if (simulation->philosophers != NULL && simulation->pids != NULL)
		return (false);
	free(simulation->philosophers);
	free(simulation->pids);
	return (true);
}

/**
 * @brief Creates semaphores for the interprocess communication and the forks.
 * 
 * @param simulation A reference to the simulation data
 *        to save the resulting addresses in.
 * 
 * @param number_of_forks The starting value
 *        of the semaphore representing the forks.
 * 
 * @return `true` if `sem_open()` fails, `false` otherwise.
 */
inline static bool
	create_the_semaphores(
		t_simulation *const simulation,
		uint8_t const number_of_forks
	)
{
	simulation->forks = sem_open(
			FORKS, O_CREAT | O_EXCL, S_IRUSR | S_IWUSR, number_of_forks);
	if (simulation->forks == SEM_FAILED)
		return (true);
	simulation->sated_philosophers = sem_open(
			SATED_PHILOSOPHERS, O_CREAT | O_EXCL, S_IRUSR | S_IWUSR, 0);
	if (simulation->sated_philosophers != SEM_FAILED)
		return (false);
	sem_close(simulation->forks);
	sem_unlink(FORKS);
	return (true);
}

/**
 * @brief Initializes the philosopher at a given index.
 *
 * @param simulation A reference to the simulation data
 *        from which to initialize the philosopher.
 *
 * @param n The index of the philosopher to initialize.
 *
 * @param arguments A reference to the program arguments
 *        to initialize the philosopher with.
 *
 * @param time_to_think How many milliseconds
 *        each philosopher must spend thinking.
 */
inline static void
	initialize_the_nth_philosopher(
		t_simulation *const simulation,
		uint8_t const n,
		t_program_arguments const *const arguments,
		uint16_t const time_to_think
	)
{
	t_philosopher *const	philosopher = &simulation->philosophers[n];
	bool const				n_is_even = (n & 1) == 0;
	bool const				number_of_philosophers_is_odd
		= (arguments->number_of_philosophers & 1) == 1;

	philosopher->forks = simulation->forks;
	philosopher->sated_philosophers = simulation->sated_philosophers;
	philosopher->timestamp = 0;
	if (n_is_even)
	{
		philosopher->timestamp += arguments->time_to_eat;
		if (n == 0 && number_of_philosophers_is_odd)
			philosopher->timestamp += arguments->time_to_eat;
	}
	philosopher->time_to_eat = arguments->time_to_eat;
	philosopher->time_to_sleep = arguments->time_to_sleep;
	philosopher->time_to_think = time_to_think;
	philosopher->remaining_meals_before_being_sated
		= arguments->number_of_times_each_philosopher_must_eat;
	philosopher->identifer = n + 1;
}

/**
 * @brief Sets up the given simulation data by allocating resources
 *        for the forks, philosopers, and process ids,
 *        and initializing each item.
 *
 * @param simulation A reference to the simulation data to set up.
 *
 * @param arguments A reference to the program arguments to use to set up
 *        the simulation data.
 *
 * @param time_to_think How many milliseconds
 *        each philosopher must spend thinking.
 *
 * @param status A reference to the status to set if the allocation fails.
 *
 * @return `true` if the allocation fails, `false` otherwise.
 */
bool
	simulation_setup(
		t_simulation *const simulation,
		t_program_arguments const *const arguments,
		uint16_t const time_to_think,
		t_status *const status
	)
{
	uint8_t	i;

	if (allocate(simulation, arguments->number_of_philosophers))
		return (*status = ERR_MALLOC, true);
	if (create_the_semaphores(simulation, arguments->number_of_philosophers))
	{
		free(simulation->philosophers);
		free(simulation->pids);
		return (*status = ERR_SEM_OPEN, true);
	}
	i = arguments->number_of_philosophers;
	while (!__builtin_sub_overflow(i, 1, &i))
		initialize_the_nth_philosopher(simulation, i, arguments, time_to_think);
	return (false);
}
