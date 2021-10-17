/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_usleep.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 16:55:43 by jodufour          #+#    #+#             */
/*   Updated: 2021/10/17 23:41:24 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "philosophers.h"
#include "type/t_ctx.h"
#include "type/t_philo.h"
#include "enum/e_state.h"
#include "enum/e_ret.h"

int	phi_philo_wait(t_philo *const philo, t_lint msec)
{
	t_lint	start;
	t_lint	now;
	t_lint	waited;
	int		ret;

	start = phi_now();
	if (start == -1)
		return (GET_TIME_OF_DAY_ERR);
	now = phi_now();
	if (now == -1)
		return (GET_TIME_OF_DAY_ERR);
	ret = SUCCESS;
	waited = now - start;
	while (waited < msec)
	{
		if (usleep(100) == -1)
			return (USLEEP_ERR);
		now = phi_now();
		if (now == -1)
			return (GET_TIME_OF_DAY_ERR);
		waited = now - start;
	}
	return (SUCCESS);
}
