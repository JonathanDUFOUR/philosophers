/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_philo.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 10:20:29 by jodufour          #+#    #+#             */
/*   Updated: 2021/10/17 23:28:54 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_PHILO_H
# define T_PHILO_H

# include <pthread.h>
# include "type/t_int.h"
# include "type/t_mutex.h"
# include "type/t_timeval.h"

typedef struct s_philo	t_philo;

struct s_philo
{
	pthread_t	thread;
	t_huint		idx;
	t_hhuint	state;
	t_lint		meal_count;
	t_lint		last_meal;
	t_mutex		*fork_right;
	t_mutex		*fork_left;
	t_mutex		access;
};

int		phi_philo_born(t_philo *philo);
int		phi_philo_eat(t_philo *const philo);
int		phi_philo_manage(t_philo *philo);
int		phi_philo_sleep(t_philo *const philo);
int		phi_philo_state_msg(t_philo *const philo);
int		phi_philo_stop(t_philo *philo);
int		phi_philo_suicide(t_philo *const philo);
int		phi_philo_think(t_philo *const philo);
int		phi_philo_wait(t_philo *const philo, t_lint ms);

void	phi_philo_init(t_philo *philo, t_mutex *fork);

#endif
