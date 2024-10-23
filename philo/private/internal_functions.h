/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal_functions.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 19:40:18 by jodufour          #+#    #+#             */
/*   Updated: 2024/10/23 22:17:34 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNAL_FUNCTIONS_H
# define INTERNAL_FUNCTIONS_H

# include "simulation_data.h"
# include <stdbool.h>

void	run_the_simulation(t_simulation_data *const simulation_data)
		__attribute__((nonnull));


bool	parse_the_arguments(
			t_program_arguments *const arguments,
			int const ac,
			char const *const *const av,
			t_status *const status)
		__attribute__((nonnull));
bool	prepare_the_simulation(
			t_simulation_data *const simulation_data,
			t_program_arguments const *const program_arguments,
			t_status *const status)
		__attribute__((nonnull));


#endif
