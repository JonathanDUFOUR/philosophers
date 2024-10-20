/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal_functions.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 19:40:18 by jodufour          #+#    #+#             */
/*   Updated: 2024/10/21 00:15:44 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNAL_FUNCTIONS_H
# define INTERNAL_FUNCTIONS_H

# include "arguments.h"
# include "philosopher.h"
# include "status.h"
# include <stdbool.h>

bool	parse_arguments(
			int const ac,
			char const *const *const av,
			t_arguments *const arguments,
			t_status *const status)
		__attribute__((nonnull));
bool	setup(
			t_arguments const *const arguments,
			t_philosopher **const philosophers,
			pthread_mutex_t **const forks,
			t_status *const status)
		__attribute__((nonnull));

#endif
