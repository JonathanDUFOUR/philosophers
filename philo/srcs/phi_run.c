/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_run.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 02:18:32 by jodufour          #+#    #+#             */
/*   Updated: 2021/10/16 10:17:31 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "philosophers.h"
#include "type/t_ctx.h"
#include "type/t_philo.h"
#include "enum/e_ret.h"

int	phi_run(void)
{
	t_uint const	nb_philo = phi_ctx_get()->nb_philo;
	t_philo			*philo;
	t_mutex			*fork;
	int				ret;

	philo = malloc(nb_philo * sizeof(t_philo));
	if (!philo)
		return (MALLOC_ERR);
	fork = malloc(nb_philo * sizeof(t_mutex));
	if (!fork)
	{
		phi_memdel(&philo);
		return (MALLOC_ERR);
	}
	phi_philo_init(philo, fork);
	ret = phi_philo_born(philo);
	if (ret == SUCCESS)
		ret = phi_philo_manage(philo);
	phi_memdel(&philo);
	phi_memdel(&fork);
	return (ret);
}
