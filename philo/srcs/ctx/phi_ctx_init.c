/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_ctx_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 21:59:44 by jodufour          #+#    #+#             */
/*   Updated: 2021/09/20 16:55:12 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type/t_ctx.h"
#include "enum/e_ret.h"

int	phi_ctx_init(char const **av)
{
	int	ret;

	ret = phi_ctx_init_nb_philo(av[1]);
	if (ret == SUCCESS)
		ret = phi_ctx_init_time_to_die(av[2]);
	if (ret == SUCCESS)
		ret = phi_ctx_init_time_to_eat(av[3]);
	if (ret == SUCCESS)
		ret = phi_ctx_init_time_to_sleep(av[4]);
	if (ret == SUCCESS)
		ret = phi_ctx_init_required_meals(av[5]);
	return (ret);
}
