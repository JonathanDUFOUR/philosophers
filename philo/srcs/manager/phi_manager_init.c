/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_manager_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 16:26:41 by jodufour          #+#    #+#             */
/*   Updated: 2021/10/19 16:44:52 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type/t_manager.h"

void	phi_manager_init(t_philo *philo, t_mutex *fork)
{
	t_manager *const	manager = phi_manager_get();

	manager->philo = philo;
	phi_philo_init(philo, fork);
}
