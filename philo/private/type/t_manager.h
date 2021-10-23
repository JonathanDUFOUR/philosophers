/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_manager.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 16:15:42 by jodufour          #+#    #+#             */
/*   Updated: 2021/10/24 00:39:43 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_MANAGER_H
# define T_MANAGER_H

# include "type/t_philo.h"

typedef struct s_manager	t_manager;

struct s_manager
{
	pthread_t	thread;
	t_philo		*philo;
};

int			phi_manager_born(t_philo *philo, int *const ret);
int			phi_manager_kill(t_philo *philo, int *const ret);
int			phi_manager_stop(t_philo *philo, int *const ret);

void		phi_manager_init(t_philo *philo, t_mutex *fork);

void		*phi_manager_routine(void *param);

t_manager	*phi_manager_get(void);

#endif
