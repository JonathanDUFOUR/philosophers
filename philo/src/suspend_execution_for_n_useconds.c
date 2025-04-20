/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suspend_execution_for_n_useconds.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:40:22 by jodufour          #+#    #+#             */
/*   Updated: 2024/11/16 23:32:04 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <unistd.h>

/* In microseconds */
#define USLEEP_DURATION	100

/**
 * @brief Suspends the execution for a given duration.
 *
 * @param duration How many microseconds to suspend the execution.
 */
void
	suspend_execution_for_n_useconds(
		__useconds_t const duration
	)
{
	struct timeval	now;
	struct timeval	start;
	__useconds_t	elapsed_time;

	gettimeofday(&now, NULL);
	gettimeofday(&start, NULL);
	elapsed_time = (now.tv_sec - start.tv_sec) * 1000000
		+ now.tv_usec - start.tv_usec;
	while (elapsed_time < duration)
	{
		usleep(USLEEP_DURATION);
		gettimeofday(&now, NULL);
		elapsed_time = (now.tv_sec - start.tv_sec) * 1000000
			+ now.tv_usec - start.tv_usec;
	}
}
