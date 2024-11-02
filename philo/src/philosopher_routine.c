/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_routine.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 01:03:02 by jodufour          #+#    #+#             */
/*   Updated: 2024/11/02 22:32:37 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal_functions.h"
#include <sys/time.h>
#include <stdio.h>

/**
 * @brief Make a given philosopher wait for its death, and then announce it.
 * 
 * @param philosopher A reference to the philosopher that will die.
 */
inline static void
	die(
		t_philosopher *const philosopher
	)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	suspend_the_thread_until_n_useconds_has_elapsed_since(
		philosopher->time_to_die, &now);
	pthread_mutex_lock(philosopher->common);
	printf("%7u %3hhu died\n",
		philosopher->time_to_die / 1000,
		philosopher->identifer);
	pthread_mutex_unlock(philosopher->common);
}

/**
 * @brief Makes a given philosopher take the two forks on its sides,
 *        announcing it for eack fork, then eat, announcing it,
 *        and finally put the two forks back on the table.
 * 
 * @param philosopher A reference to the philosopher that will take
 *        the forks, eat, and put the forks back on the table.
 */
inline static void
	eat(
		t_philosopher *const philosopher
	)
{
	pthread_mutex_lock(philosopher->forks[0]);
	pthread_mutex_lock(philosopher->common);
	printf("%7u %3hhu has taken a fork\n",
		elapsed_time_since(&philosopher->simulation_start) / 1000,
		philosopher->identifer);
	pthread_mutex_unlock(philosopher->common);
	pthread_mutex_lock(philosopher->forks[1]);
	pthread_mutex_lock(philosopher->common);
	printf("%1$7u %2$3hhu has taken a fork\n%1$7u %2$3hhu is eating\n",
		elapsed_time_since(&philosopher->simulation_start) / 1000,
		philosopher->identifer);
	pthread_mutex_unlock(philosopher->common);
	gettimeofday(&philosopher->last_meal, NULL);
	suspend_the_thread_until_n_useconds_has_elapsed_since(
		philosopher->time_to_eat, &philosopher->last_meal);
	pthread_mutex_unlock(philosopher->forks[0]);
	pthread_mutex_unlock(philosopher->forks[1]);
	pthread_mutex_lock(&philosopher->meals);
	++philosopher->number_of_meals;
	pthread_mutex_unlock(&philosopher->meals);
}

/**
 * @brief Makes a given philosopher sleep, announcing it.
 * 
 * @param philosopher A reference to the philosopher that will sleep.
 */
inline static void
	sleep(
		t_philosopher *const philosopher
	)
{
	pthread_mutex_lock(philosopher->common);
	printf("%7u %3hhu is sleeping\n",
		elapsed_time_since(&philosopher->simulation_start) / 1000,
		philosopher->identifer);
	pthread_mutex_unlock(philosopher->common);
	suspend_the_thread_until_n_useconds_has_elapsed_since(
		philosopher->time_to_eat_and_sleep, &philosopher->last_meal);
}

/**
 * @brief Makes a given philosopher think, announcing it.
 * 
 * @param philosopher A reference to the philosopher that will think.
 */
inline static void
	think(
		t_philosopher *const philosopher
	)
{
	pthread_mutex_lock(philosopher->common);
	printf("%7u %3hhu is thinking\n",
		elapsed_time_since(&philosopher->simulation_start) / 1000,
		philosopher->identifer);
	pthread_mutex_unlock(philosopher->common);
	suspend_the_thread_until_n_useconds_has_elapsed_since(
		philosopher->time_to_eat_and_sleep_and_think, &philosopher->last_meal);
}

/**
 * @brief Makes a given philosopher execute its life cycle as described below:
 *        - take the two forks on its sides
 *        - eat
 *        - put the two forks back on the table
 *        - sleep
 *        - think
 * 
 * @param raw A reference to the philosopher that will execute its life cycle.
 * 
 * @return Always `NULL`.
 */
void
	*philosopher_routine(
		void *const raw
	)
{
	t_philosopher *const	philosopher = raw;

	if (philosopher->someone_will_inevitably_die)
	{
		die(philosopher);
		return (NULL);
	}
	pthread_mutex_lock(philosopher->common);
	pthread_mutex_unlock(philosopher->common);
	gettimeofday(&philosopher->simulation_start, NULL);
	philosopher->last_meal = philosopher->simulation_start;
	pthread_mutex_lock(philosopher->common);
	while (*philosopher->at_least_1_philosopher_must_still_eat)
	{
		pthread_mutex_unlock(philosopher->common);
		eat(philosopher);
		sleep(philosopher);
		think(philosopher);
		pthread_mutex_lock(philosopher->common);
	}
	pthread_mutex_unlock(philosopher->common);
	return (NULL);
}
