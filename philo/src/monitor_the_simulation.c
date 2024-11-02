/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_the_simulation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 23:50:35 by jodufour          #+#    #+#             */
/*   Updated: 2024/11/02 23:04:05 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simulation.h"
#include <unistd.h>

/**
 * @brief Checks whether at least 1 philosopher has not reached the specified
 *        number of times they must eat yet.
 * 
 * @param philosophers The array of philosophers to check.
 * 
 * @param number_of_philosophers The number of philosophers in the array.
 * 
 * @param number_of_times_each_philosopher_must_eat The number of times each
 *        philosopher must eat.
 * 
 * @return `true` if at least 1 philosopher has not reached the specified number
 *         of times they must eat yet, `false` otherwise.
 */
inline static bool
	at_least_1_philosopher_must_still_eat(
		t_philosopher *const philosophers,
		uint8_t const number_of_philosophers,
		uint8_t const number_of_times_each_philosopher_must_eat
	)
{
	uint8_t	i;
	uint8_t	number_of_meals;

	i = 0;
	while (i < number_of_philosophers)
	{
		pthread_mutex_lock(&philosophers[i].meals);
		number_of_meals = philosophers[i].number_of_meals;
		pthread_mutex_unlock(&philosophers[i].meals);
		if (number_of_meals < number_of_times_each_philosopher_must_eat)
			return (true);
		++i;
	}
	return (false);
}

#define USLEEP_DURATION 4242 // in microseconds

/**
 * @brief Monitors the number of meals eaten by each philosopher,
 *        and stops the simulation when every philosopher has eaten
 *        at least the specified number of times.
 * 
 * @param simulation A reference to the simulation data to use to monitor it.
 * 
 * @param arguments A reference to the program arguments to use
 *        to monitor the simulation.
 */
void
	monitor_the_simulation(
		t_simulation *const simulation,
		t_program_arguments const *const arguments
	)
{
	pthread_mutex_lock(&simulation->shared);
	while (at_least_1_philosopher_must_still_eat(
			simulation->philosophers,
			arguments->number_of_philosophers,
			arguments->number_of_times_each_philosopher_must_eat))
	{
		pthread_mutex_unlock(&simulation->shared);
		usleep(USLEEP_DURATION);
		pthread_mutex_lock(&simulation->shared);
	}
	simulation->at_least_1_philosopher_must_still_eat = false;
	pthread_mutex_unlock(&simulation->shared);
}
