/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_data.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 00:40:57 by jodufour          #+#    #+#             */
/*   Updated: 2024/10/22 15:14:13 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIMULATION_DATA_H
# define SIMULATION_DATA_H

# include "philosopher.h"

typedef struct s_simulation_data	t_simulation_data;

struct s_simulation_data
{
	pthread_mutex_t	voice;
	pthread_mutex_t	*forks;
	t_philosopher	*philosophers;
};

#endif
