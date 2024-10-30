/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_arguments.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 18:07:53 by jodufour          #+#    #+#             */
/*   Updated: 2024/10/29 21:27:55 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROGRAM_ARGUMENTS_H
# define PROGRAM_ARGUMENTS_H

# include <stdint.h>

typedef struct s_program_arguments	t_program_arguments;

struct s_program_arguments
{
	// The following arguments are passed in milliseconds to the program,
	// but they shall be stored in microseconds after being parsed.
	__useconds_t	time_to_die;
	__useconds_t	time_to_eat;
	__useconds_t	time_to_sleep;

	uint8_t			number_of_philosophers;
	uint8_t			number_of_times_each_philosopher_must_eat;
};

#endif
