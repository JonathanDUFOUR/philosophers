/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_action.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 22:02:01 by jodufour          #+#    #+#             */
/*   Updated: 2021/10/10 22:10:45 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef G_ACTION_H
# define G_ACTION_H

# include "type/t_philo.h"

typedef int(*			t_action)(t_philo *philo);

static t_action const	g_action[] = {
	phi_philo_eat,
	phi_philo_sleep,
	phi_philo_think,
	NULL
};

#endif
