/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_philo_think.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 18:43:10 by jodufour          #+#    #+#             */
/*   Updated: 2021/09/25 17:32:28 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type/t_ctx.h"
#include "type/t_philo.h"
#include "enum/e_ret.h"
#include "enum/e_state.h"

int	phi_philo_think(t_philo *philo)
{
	t_ctx *const	ctx = phi_ctx_get();
	t_lint const	time_to_eat = ctx->time_to_eat;
	t_lint const	time_to_sleep = ctx->time_to_sleep;
	int				ret;

	philo->state = THINKING;
	ret = phi_philo_state_msg(philo);
	if (time_to_eat > time_to_sleep)
		ret = phi_philo_wait(philo, time_to_eat - time_to_sleep);
	return (ret);
}
