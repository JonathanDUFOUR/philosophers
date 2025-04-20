/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 20:48:51 by jodufour          #+#    #+#             */
/*   Updated: 2025/04/21 01:02:12 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_messages.h"
#include "internal_functions.h"
#include "simulation.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * @brief Prints the error message corresponding to a given status.
 *
 * @param status The status to print the error message of.
 *
 * @return Always `EXIT_FAILURE`.
 */
inline static int
	error_message(
		t_status const status
	)
{
	t_error_message const *const	message = &g_error_messages[status];
	char const						prefix[] = {
		'\x1B', '[', '1', ';', '3', '1', 'm', // Bold red
		'E', 'r', 'r', 'o', 'r',
		'\x1B', '[', '0', 'm', // Reset
		':', ' ',
	};

	write(STDERR_FILENO, prefix, sizeof(prefix));
	write(STDERR_FILENO, message->s, message->len);
	return (EXIT_FAILURE);
}

/**
 * @brief Calculates how many milliseconds each philosopher must spend thinking
 *        to allow both neighbors time to eat.
 *
 * @param arguments A reference to the program arguments to use to calculate
 *        the time to think.
 *
 * @return The calculated time to think in milliseconds.
 */
inline static uint16_t
	calculate_time_to_think(
		t_program_arguments const *const arguments
	)
{
	bool const			is_odd = arguments->number_of_philosophers & 1;
	__useconds_t const	time_to_eat_again
		= arguments->time_to_eat
		+ arguments->time_to_eat * is_odd;

	return ((time_to_eat_again > arguments->time_to_sleep)
		* (time_to_eat_again - arguments->time_to_sleep));
}

/**
 * @brief Checks whether the given program arguments will inevitably lead
 *        to a philosopher's death, and if so, suspend the execution for
 *        the time before a philosopher dies, and finally announce the death
 *        of every philosopher.
 *
 * @param arguments A reference to the program arguments to check.
 *
 * @param time_to_think How many milliseconds
 *        each philosopher must spend thinking.
 *
 * @return `true` if a philosopher will inevitably die, `false` otherwise.
 */
inline static bool
	death_was_inevitable(
		t_program_arguments *const arguments,
		uint16_t const time_to_think
	)
{
	if (arguments->number_of_philosophers > 1
		&& arguments->time_to_die
		> arguments->time_to_eat + arguments->time_to_sleep + time_to_think)
		return (false);
	suspend_execution_for_n_useconds(arguments->time_to_die * 1000);
	while (arguments->number_of_philosophers)
		printf("%7u %3hhu died\n",
			arguments->time_to_die,
			arguments->number_of_philosophers--);
	return (true);
}

int
	main(
		int const ac,
		char const *const *const av
	)
{
	t_program_arguments	arguments;
	uint16_t			time_to_think;
	t_simulation		simulation;
	t_status			status;

	if (parse_arguments(&arguments, ac, av, &status))
		return (error_message(status));
	time_to_think = calculate_time_to_think(&arguments);
	if (death_was_inevitable(&arguments, time_to_think))
		return (EXIT_SUCCESS);
	if (simulation_setup(&simulation, &arguments, time_to_think))
		return (error_message(ERR_MALLOC));
	if (simulation_launch(&simulation, arguments.number_of_philosophers))
		return (
			simulation_cleanup(&simulation, arguments.number_of_philosophers),
			error_message(ERR_PTHREAD_CREATE)
		);
	if (ac == 6)
		simulation_monitor(&simulation, &arguments);
	wait_for_threads(simulation.thread_ids, arguments.number_of_philosophers);
	simulation_cleanup(&simulation, arguments.number_of_philosophers);
	return (EXIT_SUCCESS);
}
