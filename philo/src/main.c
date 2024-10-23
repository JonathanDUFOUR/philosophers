/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 20:48:51 by jodufour          #+#    #+#             */
/*   Updated: 2024/10/23 13:51:02 by jodufour         ###   ########.fr       */
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
inline static int	error_message(t_status const status)
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

int	main(int const ac, char const *const *const av)
{
	t_program_arguments	program_arguments;
	t_simulation_data	simulation_data;
	t_status			status;

	if (parse_the_arguments(&program_arguments, ac, av, &status) || \
		prepare_the_simulation(&simulation_data, &program_arguments, &status))
		return (error_message(status));
	status = OK;
	run_the_simulation(&simulation_data);
	free(simulation_data.philosophers);
	free(simulation_data.forks);
	if (status)
		return (error_message(status));
	return (EXIT_SUCCESS);
}
