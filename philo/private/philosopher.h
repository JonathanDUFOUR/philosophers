/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 23:35:33 by jodufour          #+#    #+#             */
/*   Updated: 2024/11/08 23:59:14 by jodufour         ###   ########.fr       */
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

	/* The forks are stored as the first to take and the second to take,
	not as the left and right forks. */
	pthread_mutex_t	*forks[2];

	/* A mutex shared by all threads, to access shared data and avoid messing up
	texts when printing */
	pthread_mutex_t	*shared;

	bool			*simulation_is_running;

	/* In milliseconds */
	uint32_t		timestamp;
	/* In milliseconds */
	uint16_t		time_to_eat;
	/* In milliseconds */
	uint16_t		time_to_sleep;
	/* In milliseconds */
	uint16_t		time_to_think;

	uint8_t			number_of_meals;
	uint8_t			identifer;
};
/* Each philosopher has its own copy of the time each action takes.
Note that they do not store the time of each separate action, but
rather the global time it shall take to perform a complete cycle.
For example, given the following arguments:
- 42  (number_of_philosophers)
- 610 (time_to_die)
- 300 (time_to_eat)
- 200 (time_to_sleep)
And thus, the following calculated value:
- 100 (time_to_think)

The philosopher will only remember that:
- they shall end eating   after 300 milliseconds since their last meal
- they shall end sleeping after 500 milliseconds since their last meal
- they shall end thinking after 600 milliseconds after their last meal */

#endif
