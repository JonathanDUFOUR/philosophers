/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suspend_the_thread_until_n_useconds_has_ela        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:40:22 by jodufour          #+#    #+#             */
/*   Updated: 2024/11/02 21:25:46 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal_functions.h"
#include <sys/time.h>
#include <unistd.h>

#define USLEEP_DURATION	100 // In microseconds

/**
 * @brief Suspends the calling thread until the given duration has elapsed
 *        since the given start time.
 * 
 * @param duration The duration to wait for in microseconds.
 * 
 * @param start The start time to calculate the elapsed time since.
 */
void
	suspend_the_thread_until_n_useconds_has_elapsed_since(
		__useconds_t const duration,
		struct timeval const *const start
	)
{
	while (elapsed_time_since(start) < duration)
		usleep(USLEEP_DURATION);
}
