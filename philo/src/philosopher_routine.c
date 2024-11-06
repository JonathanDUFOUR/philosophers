/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_routine.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 01:03:02 by jodufour          #+#    #+#             */
/*   Updated: 2024/11/05 15:34:12 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal_functions.h"
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
	suspend_the_thread_for_n_useconds(philosopher->time_to_die * 1000);
	pthread_mutex_lock(philosopher->shared);
	printf("%7u %3hhu died\n",
		philosopher->time_to_die,
		philosopher->identifer);
	pthread_mutex_unlock(philosopher->shared);
}

/**
 * @brief Makes a given philosopher take the two forks on its sides,
 *        announcing it for eack fork, then eat, announcing it,
 *        and finally put the two forks back on the table.
 * 
 * @param philosopher A reference to the philosopher that will take
 *        the forks, eat, and put the forks back on the table.
 * 
 * @param time_to_eat How many microseconds the philosopher must eat.
 */
inline static void
	eat(
		t_philosopher *const philosopher,
		__useconds_t const time_to_eat
	)
{
	pthread_mutex_lock(philosopher->forks[0]);
	pthread_mutex_lock(philosopher->shared);
	printf("%7u %3hhu has taken a fork\n",
		philosopher->timestamp,
		philosopher->identifer);
	pthread_mutex_unlock(philosopher->shared);
	pthread_mutex_lock(philosopher->forks[1]);
	pthread_mutex_lock(philosopher->shared);
	printf("%1$7u %2$3hhu has taken a fork\n%1$7u %2$3hhu is eating\n",
		philosopher->timestamp,
		philosopher->identifer);
	pthread_mutex_unlock(philosopher->shared);
	suspend_the_thread_for_n_useconds(time_to_eat);
	philosopher->timestamp += philosopher->time_to_eat;
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
 * 
 * @param time_to_sleep How many microseconds the philosopher must sleep.
 */
inline static void
	sleep(
		t_philosopher *const philosopher,
		__useconds_t const time_to_sleep
	)
{
	pthread_mutex_lock(philosopher->shared);
	printf("%7u %3hhu is sleeping\n",
		philosopher->timestamp,
		philosopher->identifer);
	pthread_mutex_unlock(philosopher->shared);
	suspend_the_thread_for_n_useconds(time_to_sleep);
	philosopher->timestamp += philosopher->time_to_sleep;
}

/**
 * @brief Makes a given philosopher think, announcing it.
 * 
 * @param philosopher A reference to the philosopher that will think.
 * 
 * @param time_to_think How many microseconds the philosopher must think.
 */
inline static void
	think(
		t_philosopher *const philosopher,
		__useconds_t const time_to_think
	)
{
	pthread_mutex_lock(philosopher->shared);
	printf("%7u %3hhu is thinking\n",
		philosopher->timestamp,
		philosopher->identifer);
	pthread_mutex_unlock(philosopher->shared);
	suspend_the_thread_for_n_useconds(time_to_think);
	philosopher->timestamp += philosopher->time_to_think;
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
	__useconds_t const		time_to_eat = philosopher->time_to_eat * 1000;
	__useconds_t const		time_to_sleep = philosopher->time_to_sleep * 1000;
	__useconds_t const		time_to_think = philosopher->time_to_think * 1000;

	if (philosopher->someone_will_inevitably_die)
	{
		die(philosopher);
		return (NULL);
	}
	pthread_mutex_lock(philosopher->shared);
	pthread_mutex_unlock(philosopher->shared);
	suspend_the_thread_for_n_useconds(philosopher->timestamp * 1000);
	pthread_mutex_lock(philosopher->shared);
	while (*philosopher->simulation_is_running)
	{
		pthread_mutex_unlock(philosopher->shared);
		eat(philosopher, time_to_eat);
		sleep(philosopher, time_to_sleep);
		think(philosopher, time_to_think);
		pthread_mutex_lock(philosopher->shared);
	}
	pthread_mutex_unlock(philosopher->shared);
	return (NULL);
}
