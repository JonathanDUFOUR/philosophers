/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 23:35:33 by jodufour          #+#    #+#             */
/*   Updated: 2024/10/23 20:11:31 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include "program_arguments.h"
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philosopher	t_philosopher;

struct s_philosopher
{
	// The forks are stored as the first to take and the second to take,
	// not as the left and right forks.
	pthread_mutex_t const	*forks[2];

	// Each philosopher has its own copy of the common
	// times to die, eat, sleep, and think, in microseconds.
	__useconds_t			time_to_die;
	__useconds_t			time_to_eat;
	__useconds_t			time_to_sleep;
	__useconds_t			time_to_think;

	__useconds_t			elapsed_time_since_last_meal;
	__UINT8_TYPE__			number_of_meals;
};

#endif
