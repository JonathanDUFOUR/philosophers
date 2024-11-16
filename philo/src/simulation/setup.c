/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 23:56:55 by jodufour          #+#    #+#             */
/*   Updated: 2024/11/16 23:29:05 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simulation.h"
#include <stdlib.h>

/**
 * @brief Allocates memory for the forks, philosophers, and thread ids.
 * 
 * @param simulation A reference to the simulation data
 *        to save the resulting addresses in.
 * 
 * @param n How many forks, philosophers, and tread ids to allocate memory for.
 * 
 * @return `true` if `malloc()` fails, `false` otherwise.
 */
inline static bool
	allocate(
		t_simulation *const simulation,
		uint8_t const n
	)
{
	simulation->forks = malloc(n * sizeof(*simulation->forks));
	if (simulation->forks == NULL)
		return (true);
	simulation->philosophers = malloc(n * sizeof(*simulation->philosophers));
	if (simulation->philosophers == NULL)
	{
		free(simulation->forks);
		return (true);
	}
	simulation->thread_ids = malloc(n * sizeof(*simulation->thread_ids));
	if (simulation->thread_ids == NULL)
	{
		free(simulation->forks);
		free(simulation->philosophers);
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

	pthread_mutex_init(&philosopher->meals, NULL);
	philosopher->shared = &simulation->shared;
	philosopher->simulation_is_running = &simulation->is_running;
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
 * @param time_to_think How many milliseconds
 *        each philosopher must spend thinking.
 */
inline static void
	initialize_the_forks_and_the_philosophers(
		t_simulation *const simulation,
		t_program_arguments const *const arguments,
		uint16_t const time_to_think
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
 * @param time_to_think How many milliseconds
 *        each philosopher must spend thinking.
 * 
 * @return `true` if `malloc()` fails, `false` otherwise.
 */
bool
	simulation_setup(
		t_simulation *const simulation,
		t_program_arguments const *const arguments,
		uint16_t const time_to_think
	)
{
	if (allocate(simulation, arguments->number_of_philosophers))
		return (true);
	pthread_mutex_init(&simulation->shared, NULL);
	initialize_the_forks_and_the_philosophers(
		simulation, arguments, time_to_think);
	simulation->is_running = false;
	return (false);
}
