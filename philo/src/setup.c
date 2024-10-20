/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 23:56:55 by jodufour          #+#    #+#             */
/*   Updated: 2024/10/21 00:14:41 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arguments.h"
#include "philosopher.h"
#include "status.h"
#include <stdbool.h>

/**
 * @brief Allocates and initializes the philosophers and the forks.
 * 
 * @param arguments A reference to the arguments to use
 *                  to setup the philosophers and the forks.
 * @param philosophers A reference to the array of philosophers
 *                     to allocate and initialize.
 * @param forks A reference to the array of forks
 *              to allocate and initialize.
 * @param status A reference to the status to set if the setup fails.
 * 
 * @return `true` if the setup fails, `false` otherwise.
 */
bool	setup(
	t_arguments const *const arguments,
	t_philosopher **const philosophers,
	pthread_mutex_t **const forks,
	t_status *const status)
{
	(void)arguments;
	(void)philosophers;
	(void)forks;
	(void)status;
	return (false);
}
