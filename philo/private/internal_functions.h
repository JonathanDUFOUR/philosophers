/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal_functions.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 19:40:18 by jodufour          #+#    #+#             */
/*   Updated: 2024/11/09 00:58:48 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNAL_FUNCTIONS_H
# define INTERNAL_FUNCTIONS_H

# include "simulation.h"
# include "status.h"

void
clean_the_simulation(
	t_simulation *const simulation,
	uint8_t number_of_philosophers)
__attribute__((nonnull));

bool
launch_the_simulation(
	t_simulation *const simulation,
	uint8_t const number_of_philosophers)
__attribute__((nonnull));

void
monitor_the_simulation(
	t_simulation *const simulation,
	t_program_arguments const *const arguments)
__attribute__((nonnull));

bool
parse_the_arguments(
	t_program_arguments *const arguments,
	int const ac,
	char const *const *const av,
	t_status *const status)
__attribute__((nonnull));

void
*philosopher_routine(
	void *const philosopher)
__attribute__((nonnull));

bool
prepare_the_simulation(
	t_simulation *const simulation,
	t_program_arguments const *const program_arguments,
	uint16_t const time_to_think)
__attribute__((nonnull));

void
suspend_the_execution_for_n_useconds(
	__useconds_t const duration);

void
wait_for_threads(
	pthread_t *const thread_ids,
	uint8_t number_of_threads)
__attribute__((nonnull));

#endif
