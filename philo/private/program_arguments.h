/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_arguments.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 18:07:53 by jodufour          #+#    #+#             */
/*   Updated: 2024/10/23 22:10:21 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROGRAM_ARGUMENTS_H
# define PROGRAM_ARGUMENTS_H

typedef struct s_program_arguments	t_program_arguments;

struct s_program_arguments
{
	// All the following times are in milliseconds.
	__UINT16_TYPE__	time_to_die;
	__UINT16_TYPE__	time_to_eat;
	__UINT16_TYPE__	time_to_sleep;
	__UINT8_TYPE__	number_of_philosophers;
	__UINT8_TYPE__	number_of_time_each_philosopher_must_eat;
};

#endif
