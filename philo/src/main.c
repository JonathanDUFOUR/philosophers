/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 20:48:51 by jodufour          #+#    #+#             */
/*   Updated: 2024/10/21 00:15:53 by jodufour         ###   ########.fr       */
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
	t_status		status;
	t_arguments		arguments;
	t_philosopher	*philosophers;
	pthread_mutex_t	*forks;

	if (parse_arguments(ac, av, &arguments, &status)
		|| setup(&arguments, &philosophers, &forks, &status))
		return (error_message(status));
	return (EXIT_SUCCESS);
}
