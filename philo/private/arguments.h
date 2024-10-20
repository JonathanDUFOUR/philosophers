/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 18:07:53 by jodufour          #+#    #+#             */
/*   Updated: 2024/10/20 23:33:07 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGUMENTS_H
# define ARGUMENTS_H

typedef struct s_arguments	t_arguments;

struct s_arguments
{
	__UINT16_TYPE__	time_to_die;
	__UINT16_TYPE__	time_to_eat;
	__UINT16_TYPE__	time_to_sleep;
	__UINT8_TYPE__	number_of_philosophers;
	__UINT8_TYPE__	number_of_time_each_philosopher_must_eat;
};

#endif
