/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_the_simulation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 23:56:55 by jodufour          #+#    #+#             */
/*   Updated: 2024/10/23 13:56:36 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simulation_data.h"
#include "status.h"
#include <stdbool.h>
#include <stdlib.h>

/**
 * @brief Allocates memory for the philosophers and forks.
 * 
 * @param simulation_data A reference to the simulation data to save
 *                        the addresses of the allocations in.
 * @param number_of_philosophers The number of philosophers/forks to allocate.
 * 
 * @return `true` if the malloc() fails, `false` otherwise.
 */
inline static bool	allocate(
	t_simulation_data *const simulation_data,
	__UINT8_TYPE__ const number_of_philosophers)
{
	simulation_data->forks = \
		malloc(number_of_philosophers * sizeof(*simulation_data->forks));
	if (!simulation_data->forks)
		return (true);
	simulation_data->philosophers = \
		malloc(number_of_philosophers * sizeof(*simulation_data->philosophers));
	if (!simulation_data->philosophers)
	{
		free(simulation_data->forks);
		return (true);
	}
	return (false);
}

/**
 * @brief Initializes the fork and the philosopher at a given index.
 * 
 * @param simulation_data A reference to the simulation data
 *                        from which to initialize the fork and philosopher.
 * @param n The index of the fork/philosopher to initialize.
 * @param philosopher_forks The indices of the forks
 *                          to initialize the philosopher with.
 * @param program_arguments A reference to the program arguments
 *                          to initialize the philosopher with.
 */
inline static void	initialize_the_nth_fork_and_philosopher(
	t_simulation_data *const simulation_data,
	size_t const n,
	size_t const *const philosopher_forks,
	t_program_arguments const *const program_arguments)
{
	pthread_mutex_t *const	forks = simulation_data->forks;
	t_philosopher *const	philosopher = &simulation_data->philosophers[n];

	forks[n] = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
	philosopher->forks[0] = &forks[philosopher_forks[0]];
	philosopher->forks[1] = &forks[philosopher_forks[1]];
	philosopher->time_to_die = program_arguments->time_to_die * 1000;
	philosopher->time_to_eat = program_arguments->time_to_eat * 1000;
	philosopher->time_to_sleep = program_arguments->time_to_sleep * 1000;
	philosopher->time_to_think = 42;
	if (philosopher->time_to_eat >= philosopher->time_to_sleep)
		philosopher->time_to_think += \
			philosopher->time_to_eat - philosopher->time_to_sleep;
	philosopher->number_of_meals = 0;
}

/**
 * @return `true` if the given integer is odd, `false` otherwise.
 */
inline static bool	is_odd(__UINT8_TYPE__ const n)
{
	return (n & 1);
}

/**
 * @brief Initializes the given simulation data.
 * 
 * @param simulation_data A reference to the simulation data to initialize.
 * @param program_arguments A reference to the program arguments to use
 *                          to initialize the simulation data.
 */
inline static void	initialize(
	t_simulation_data *const simulation_data,
	t_program_arguments const *const program_arguments)
{
	size_t const	last = program_arguments->number_of_philosophers - 1;
	size_t			i;

	simulation_data->voice = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
	i = 0;
	while (i < last)
	{
		initialize_the_nth_fork_and_philosopher(
			simulation_data, i, (size_t []){i, i + 1}, program_arguments);
		++i;
		if (i == last)
			break ;
		initialize_the_nth_fork_and_philosopher(
			simulation_data, i, (size_t []){i + 1, i}, program_arguments);
		++i;
	}
	if (is_odd(last))
		initialize_the_nth_fork_and_philosopher(
			simulation_data, last, (size_t []){0, last}, program_arguments);
	else
		initialize_the_nth_fork_and_philosopher(
			simulation_data, last, (size_t []){last, 0}, program_arguments);
}

/**
 * @brief Sets up the given simulation data by allocating memory
 *        for the philosophers and forks, and initializing each item.
 * 
 * @param simulation_data A reference to the simulation data to set up.
 * @param program_arguments A reference to the program arguments to use
 *                          to set up the simulation data.
 * @param status A reference to the status to set if an error occurs.
 * 
 * @return `true` if an error occurs, `false` otherwise.
 */
bool	prepare_the_simulation(
	t_simulation_data *const simulation_data,
	t_program_arguments const *const program_arguments,
	t_status *const status)
{
	if (allocate(simulation_data, program_arguments->number_of_philosophers))
		return (*status = ERR_MALLOC, true);
	initialize(simulation_data, program_arguments);
	return (false);
}
