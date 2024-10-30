/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_the_simulation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 02:32:10 by jodufour          #+#    #+#             */
/*   Updated: 2024/10/29 02:32:56 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simulation.h"
#include <stdlib.h>

/**
 * @brief Frees the memory allocated for the forks, philosophers, and threads.
 * 
 * @param simulation A reference to the simulation data to clean.
 */
void	clean_the_simulation(t_simulation *const simulation)
{
	free(simulation->forks);
	free(simulation->philosophers);
	free(simulation->threads);
}
