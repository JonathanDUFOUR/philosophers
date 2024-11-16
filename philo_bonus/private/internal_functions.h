/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal_functions.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 19:40:18 by jodufour          #+#    #+#             */
/*   Updated: 2024/11/14 21:34:13 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNAL_FUNCTIONS_H
# define INTERNAL_FUNCTIONS_H

# include "program_arguments.h"
# include "status.h"
# include <stdbool.h>
# include <sys/types.h>

bool
parse_arguments(
	t_program_arguments *const arguments,
	char const *const *const av,
	t_status *const status)
__attribute__((nonnull));

void
suspend_execution_for_n_useconds(
	__useconds_t const duration);

void
wait_for_processes(
	pid_t *const pids,
	uint8_t number_of_threads)
__attribute__((nonnull));

#endif
