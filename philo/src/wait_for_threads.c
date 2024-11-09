/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_for_threads.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 02:36:53 by jodufour          #+#    #+#             */
/*   Updated: 2024/11/09 00:59:13 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdint.h>

/**
 * @brief Waits for given threads to finish.
 * 
 * @param threads An array of threads to wait for. It is assumed
 *        that the threads are all joinable.
 * 
 * @param number_of_threads How many elements does `threads` contain.
 */
void
	wait_for_threads(
		pthread_t *const thread_ids,
		uint8_t number_of_threads
	)
{
	while (number_of_threads)
		pthread_join(thread_ids[--number_of_threads], NULL);
}
