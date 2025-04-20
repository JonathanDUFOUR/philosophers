/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_for_threads.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 02:36:53 by jodufour          #+#    #+#             */
/*   Updated: 2024/11/18 13:01:26 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdint.h>

/**
 * @brief Waits for given threads to finish.
 *
 * @param thread_ids The ids of the threads to wait for. It is assumed
 *        that the threads are all joinable.
 *
 * @param number_of_threads How many elements `thread_ids` contains.
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
