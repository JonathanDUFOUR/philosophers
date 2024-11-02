/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suspend_the_thread_for_n_useconds.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:40:22 by jodufour          #+#    #+#             */
/*   Updated: 2024/11/02 23:28:53 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal_functions.h"
#include <sys/time.h>
#include <unistd.h>

/**
 * @brief Calculates how many microseconds have been elapsed since a given
 *        time. It is assumed that the result fits in a `__useconds_t`, and
 *        that the given time represent a past time.
 * 
 * @param earlier A reference to the earlier time value from which to calculate
 *        the elapsed time.
 * 
 * @return How many microseconds have been elapsed since `earlier`.
 */
__useconds_t
	elapsed_time_since(
		struct timeval const *const earlier
	)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return ((now.tv_sec - earlier->tv_sec) * 1000000
		+ now.tv_usec - earlier->tv_usec);
}

/* In microseconds */
#define USLEEP_DURATION	100

/**
 * @brief Suspends the calling thread until the given duration has elapsed
 *        since the given start time.
 * 
 * @param duration How many microseconds shall elapse since `start`.
 */
void
	suspend_the_thread_for_n_useconds(
		__useconds_t const duration
	)
{
	struct timeval	start;

	gettimeofday(&start, NULL);
	while (elapsed_time_since(&start) < duration)
		usleep(USLEEP_DURATION);
}
