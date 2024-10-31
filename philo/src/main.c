/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 20:48:51 by jodufour          #+#    #+#             */
/*   Updated: 2024/10/31 22:48:00 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_messages.h"
#include "internal_functions.h"
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

int
	main(
		int const ac,
		char const *const *const av
	)
{
	t_program_arguments	arguments;
	t_simulation		simulation;
	t_status			status;

	if (parse_the_arguments(&arguments, ac, av, &status) || \
		prepare_the_simulation(&simulation, &arguments, &status))
		return (error_message(status));
	status = OK;
	if (!launch_the_simulation(
			&simulation, arguments.number_of_philosophers, &status))
	{
		if (ac == 6)
			monitor_the_simulation(&simulation, &arguments);
		wait_for_all_threads(
			simulation.threads, arguments.number_of_philosophers);
	}
	clean_the_simulation(&simulation, arguments.number_of_philosophers);
	if (status != OK)
		return (error_message(status));
	return (EXIT_SUCCESS);
}
