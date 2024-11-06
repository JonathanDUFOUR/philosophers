/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 00:40:57 by jodufour          #+#    #+#             */
/*   Updated: 2024/11/06 20:12:06 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIMULATION_H
# define SIMULATION_H

# include "philosopher.h"

typedef struct s_simulation	t_simulation;

struct s_simulation
{
	pthread_mutex_t	shared;
	pthread_mutex_t	*forks;
	t_philosopher	*philosophers;
	pthread_t		*thread_ids;
	bool			someone_will_inevitably_die;
	bool			is_running;
};

#endif
