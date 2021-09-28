/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_philo_sleep.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 18:41:33 by jodufour          #+#    #+#             */
/*   Updated: 2021/09/15 17:35:48 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "type/t_ctx.h"
#include "type/t_philo.h"
#include "enum/e_ret.h"
#include "enum/e_state.h"

int	phi_philo_sleep(t_philo *philo)
{
	t_ctx *const	ctx = phi_ctx_get();
	int				ret;

	philo->state = SLEEPING;
	ret = phi_philo_state_msg(philo);
	if (ret == SUCCESS)
		ret = phi_philo_wait(philo, ctx->time_to_sleep);
	return (ret);
}
