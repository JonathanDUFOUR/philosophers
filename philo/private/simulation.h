/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 00:40:57 by jodufour          #+#    #+#             */
/*   Updated: 2024/11/02 21:52:49 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIMULATION_H
# define SIMULATION_H

# include "philosopher.h"

typedef struct s_simulation	t_simulation;

struct s_simulation
{
	pthread_mutex_t	common;
	pthread_mutex_t	*forks;
	t_philosopher	*philosophers;
	pthread_t		*threads;
	bool			someone_will_inevitably_die;
	bool			at_least_1_philosopher_must_still_eat;
};

#endif
