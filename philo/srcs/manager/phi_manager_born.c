/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_manager_born.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:58:55 by jodufour          #+#    #+#             */
/*   Updated: 2021/10/24 00:42:45 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type/t_manager.h"
#include "enum/e_ret.h"

int	phi_manager_born(t_philo *philo, int *const ret)
{
	t_manager *const	manager = phi_manager_get();

	if (pthread_create(&manager->thread, NULL, phi_manager_routine, manager))
		return (*ret = PTHREAD_CREATE_ERR);
	if (phi_philo_born(philo, ret))
		return (*ret);
	return (*ret = SUCCESS);
}
