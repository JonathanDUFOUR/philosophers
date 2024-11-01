/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_the_simulation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 23:56:55 by jodufour          #+#    #+#             */
/*   Updated: 2024/10/31 22:46:58 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simulation.h"
#include "status.h"
#include <stdlib.h>

/**
 * @brief Allocates memory for the philosophers and forks.
 * 
 * @param simulation A reference to the simulation data
 *        to save the addresses of the allocations in.
 * 
 * @param number_of_philosophers The number of philosophers/forks to allocate.
 * 
 * @return `true` if `malloc()` fails, `false` otherwise.
 */
inline static bool
	allocate(
		t_simulation *const simulation,
		uint8_t const number_of_philosophers
	)
{
	simulation->forks = malloc(
			number_of_philosophers * sizeof(*simulation->forks));
	if (simulation->forks == NULL)
		return (true);
	simulation->philosophers = malloc(
			number_of_philosophers * sizeof(*simulation->philosophers));
	if (simulation->philosophers == NULL)
	{
		free(simulation->forks);
		return (true);
	}
	simulation->threads = malloc(
			number_of_philosophers * sizeof(*simulation->threads));
	if (simulation->threads == NULL)
	{
		free(simulation->philosophers);
		free(simulation->forks);
		return (true);
	}
	return (false);
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
 * @param time_to_think How many microseconds the philosopher must think.
 */
inline static void
	initialize_the_nth_philosopher(
		t_simulation *const simulation,
		uint8_t const n,
		t_program_arguments const *const arguments,
		__useconds_t const time_to_think
	)
{
	t_philosopher *const	philosopher = &simulation->philosophers[n];

	pthread_mutex_init(&philosopher->meals, NULL);
	philosopher->common = &simulation->common;
	philosopher->simulation_is_running = &simulation->is_running;
	philosopher->time_to_die = arguments->time_to_die;
	philosopher->time_to_eat = arguments->time_to_eat;
	philosopher->time_to_sleep = arguments->time_to_sleep;
	philosopher->time_to_think = time_to_think;
	philosopher->number_of_meals = 0;
	philosopher->identifer = n + 1;
}

/**
 * @brief Initializes the array of forks and the array of philosophers
 *        in a given simulation data.
 * 
 * @param simulation A reference to the simulation data to initialize.
 * 
 * @param arguments A reference to the program arguments to use to initialize
 *        the simulation data.
 * 
 * @param time_to_think How many microseconds the philosophers must think.
 */
inline static void
	initialize_the_forks_and_the_philosophers(
		t_simulation *const simulation,
		t_program_arguments const *const arguments,
		__useconds_t const time_to_think
	)
{
	uint8_t	i;

	i = arguments->number_of_philosophers - 1;
	pthread_mutex_init(&simulation->forks[i], NULL);
	simulation->philosophers[i].forks[0] = &simulation->forks[0];
	simulation->philosophers[i].forks[1] = &simulation->forks[i];
	initialize_the_nth_philosopher(simulation, i, arguments, time_to_think);
	while (!__builtin_sub_overflow(i, 1, &i))
	{
		pthread_mutex_init(&simulation->forks[i], NULL);
		simulation->philosophers[i].forks[0] = &simulation->forks[i + 0];
		simulation->philosophers[i].forks[1] = &simulation->forks[i + 1];
		initialize_the_nth_philosopher(simulation, i, arguments, time_to_think);
		if (__builtin_sub_overflow(i, 1, &i))
			return ;
		pthread_mutex_init(&simulation->forks[i], NULL);
		simulation->philosophers[i].forks[0] = &simulation->forks[i + 1];
		simulation->philosophers[i].forks[1] = &simulation->forks[i + 0];
		initialize_the_nth_philosopher(simulation, i, arguments, time_to_think);
	}
}

/**
 * @brief Sets up the given simulation data by allocating memory
 *        for the philosophers and forks, and initializing each item.
 * 
 * @param simulation A reference to the simulation data to set up.
 * 
 * @param arguments A reference to the program arguments to use to set up
 *        the simulation data.
 * 
 * @param status A reference to the status to set if an allocation fails.
 * 
 * @return `true` if `malloc()` fails, `false` otherwise.
 */
bool
	prepare_the_simulation(
		t_simulation *const simulation,
		t_program_arguments const *const arguments,
		t_status *const status
	)
{
	bool const			is_odd = arguments->number_of_philosophers & 1;
	__useconds_t const	time_to_eat_again
		= arguments->time_to_eat
		+ arguments->time_to_eat * is_odd;
	__useconds_t const	time_to_think
		= (time_to_eat_again > arguments->time_to_sleep)
		* (time_to_eat_again - arguments->time_to_sleep);

	if (allocate(simulation, arguments->number_of_philosophers))
		return (*status = ERR_MALLOC, true);
	pthread_mutex_init(&simulation->common, NULL);
	initialize_the_forks_and_the_philosophers(
		simulation, arguments, time_to_think);
	simulation->is_running = false;
	return (false);
}
