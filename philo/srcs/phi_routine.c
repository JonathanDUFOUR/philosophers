/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_routine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 20:21:26 by jodufour          #+#    #+#             */
/*   Updated: 2021/10/15 20:34:04 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type/t_philo.h"
#include "enum/e_ret.h"

void	*phi_routine(void *param)
{
	t_philo *const	philo = (t_philo *)param;
	int				ret;
	int				i;

	i = 0;
	while (i < 30)
	{
		ret = phi_philo_eat(philo);
		if (ret == SUCCESS)
			ret = phi_philo_sleep(philo);
		if (ret == SUCCESS)
			ret = phi_philo_think(philo);
		++i;
	}
	return (NULL);
}
