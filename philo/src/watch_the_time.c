/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watch_the_time.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:40:22 by jodufour          #+#    #+#             */
/*   Updated: 2024/10/30 15:55:20 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal_functions.h"
#include <sys/time.h>
#include <unistd.h>

#define USLEEP_DURATION	100 // In microseconds

/**
 * @brief Suspends the calling thread until
 *        either the given duration has elapsed
 *        or the given philosopher dies.
 * 
 * @param duration How many microseconds the calling thread shall be suspended.
 * 
 * @param philosopher A reference to the philosopher to check for the death.
 * 
 * @return `true` if the philosopher dies, `false` otherwise.
 */
bool	watch_the_time(
	__useconds_t const duration,
	t_philosopher *const philosopher)
{
	struct timeval	start;

	gettimeofday(&start, NULL);
	while (elapsed_time_since(&start) < duration
		&& elapsed_time_since(&philosopher->last_meal)
		< philosopher->time_to_die)
		usleep(USLEEP_DURATION);
	return (elapsed_time_since(&philosopher->last_meal)
		>= philosopher->time_to_die);
}
