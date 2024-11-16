/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 00:40:57 by jodufour          #+#    #+#             */
/*   Updated: 2024/11/14 17:49:56 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIMULATION_H
# define SIMULATION_H

# include "philosopher.h"
# include "program_arguments.h"
# include "status.h"
# include <stdbool.h>

typedef struct s_simulation	t_simulation;

struct s_simulation
{
	sem_t			*forks;
	t_philosopher	*philosophers;
	pid_t			*pids;
	sem_t			*sated_philosophers;
};

void
simulation_cleanup(
	t_simulation *const simulation)
__attribute__((nonnull));

bool
simulation_launch(
	t_simulation *const simulation,
	uint8_t const number_of_philosophers,
	t_status *const status)
__attribute__((nonnull));

void
simulation_monitor(
	t_simulation *const simulation,
	uint8_t number_of_hungry_philosophers)
__attribute__((nonnull));

bool
simulation_setup(
	t_simulation *const simulation,
	t_program_arguments const *const program_arguments,
	uint16_t const time_to_think,
	t_status *const status)
__attribute__((nonnull));

#endif
