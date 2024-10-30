/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 23:35:33 by jodufour          #+#    #+#             */
/*   Updated: 2024/10/30 16:45:03 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include "program_arguments.h"
# include <bits/types/struct_timeval.h>
# include <pthread.h>
# include <stdbool.h>

typedef struct s_philosopher	t_philosopher;

struct s_philosopher
{
	pthread_mutex_t	meals;

	struct timeval	simulation_start;
	struct timeval	last_meal;

	// The forks are stored as the first to take and the second to take,
	// not as the left and right forks.
	pthread_mutex_t	*forks[2];

	pthread_mutex_t	*common;

	bool			*simulation_is_running;

	// Each philosopher has its own copy of the common
	// times to die, eat, sleep, and think, in microseconds.
	__useconds_t	time_to_die;
	__useconds_t	time_to_eat;
	__useconds_t	time_to_sleep;
	__useconds_t	time_to_think;

	uint8_t			number_of_meals;
	uint8_t			identifer;
};

#endif
