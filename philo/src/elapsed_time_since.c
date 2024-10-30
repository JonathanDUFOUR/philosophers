/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elapsed_time_since.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:42:03 by jodufour          #+#    #+#             */
/*   Updated: 2024/10/30 15:46:33 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <stddef.h>

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
__useconds_t	elapsed_time_since(struct timeval const *const earlier)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return ((now.tv_sec - earlier->tv_sec) * 1000000
		+ now.tv_usec - earlier->tv_usec);
}
