/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_ctx_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 21:59:44 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/08 04:06:14 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type/t_ctx.h"
#include "enum/e_ret.h"

int	phi_ctx_init(char const **av, int *const ret)
{
	if (phi_ctx_init_nb_philo(av[1], ret)
		|| phi_ctx_init_time_to_die(av[2], ret)
		|| phi_ctx_init_time_to_eat(av[3], ret)
		|| phi_ctx_init_time_to_sleep(av[4], ret)
		|| phi_ctx_init_required_meals(av[5], ret))
		return (*ret);
	return (*ret = SUCCESS);
}
