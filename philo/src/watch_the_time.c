/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watch_the_time.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:06:19 by jodufour          #+#    #+#             */
/*   Updated: 2024/10/23 22:03:57 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"
#include <stdbool.h>
#include <unistd.h>

// In microseconds
#define USLEEP_DURATION	100

/**
 * @brief Calculates how many microseconds have been elapsed between 2 given
 *        times. It is assumed that the result fits in a `__useconds_t`.
 * 
 * @param earlier A reference to the earlier time value from which to calculate
 *                the elapsed time.
 * @param later A reference to the later time value from which to calculate
 *              the elapsed time.
 * 
 * @return How many microseconds have been elapsed since `earlier`.
 */
inline static __useconds_t	elapsed_time_between(
	struct timeval const *const earlier,
	struct timeval const *const later)
{
	return ((later->tv_sec - earlier->tv_sec) * 1000000
		+ later->tv_usec - earlier->tv_usec);
}

/**
 * @brief Suspends the calling thread until
 *        either the given duration has elapsed
 *        or the given philosopher dies.
 * 
 * @param duration How many microseconds the calling thread shall be suspended.
 * @param philosopher A reference to the philosopher to check for the death.
 * 
 * @return `true` if the philosopher dies, `false` otherwise.
 */
bool	watch_the_time(
	__useconds_t const duration,
	t_philosopher *const philosopher)
{
	struct timeval	start;
	struct timeval	now;
	__useconds_t	elapsed_time_since_start;

	gettimeofday(&start, NULL);
	gettimeofday(&now, NULL);
	elapsed_time_since_start = elapsed_time_between(&start, &now);
	while (elapsed_time_since_start < duration)
	{
		philosopher->elapsed_time_since_last_meal += elapsed_time_since_start;
		if (philosopher->elapsed_time_since_last_meal >= \
			philosopher->time_to_die)
			return (true);
		usleep(USLEEP_DURATION);
		gettimeofday(&now, NULL);
		elapsed_time_since_start = elapsed_time_between(&start, &now);
	}
	philosopher->elapsed_time_since_last_meal += elapsed_time_since_start;
	if (philosopher->elapsed_time_since_last_meal >= philosopher->time_to_die)
		return (true);
	return (false);
}
